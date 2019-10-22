//
// Created by sebas on 9/10/19.
//

#include <SDL_quit.h>
#include <SDL_system.h>
#include "EntradaUsuario.h"
#include "../servicios/Locator.h"
#include "../modelo/Personaje.h"
#include <unistd.h>
#include <sys/socket.h>
#include <SDL_timer.h>
#include "../graficos/Sprite.h"

Accion *EntradaNula::getAccion() {
    return nullptr;
}

EntradaMenuSeleccion::EntradaMenuSeleccion(Entidad *pantalla) :
        pantalla(pantalla) {}

Accion *EntradaMenuSeleccion::getAccion() {
    if (framesInactivo == 0) {
        if (activo) {
            const Uint8 *entrada = SDL_GetKeyboardState(nullptr);
            auto *personaje = pantalla->getEstado<Personaje>("personaje marcado");

            if (entrada[SDL_SCANCODE_LEFT]) {
                cambiarAlPersonajeAnterior(personaje);
                framesInactivo = framesPorAccion;

            } else if (entrada[SDL_SCANCODE_RIGHT]) {
                cambiarAlPersonajeSiguiente(personaje);
                framesInactivo = framesPorAccion;

            } else if (entrada[SDL_SCANCODE_RETURN]) {
                activo = false;
                Locator::logger()->log(DEBUG, "Se selecciono enter.");
                switch (personaje->getPersonaje()) {
                    case GUY:
                        Locator::logger()->log(DEBUG, "Se selecciono guy.");
                        return new Accion(SELECCIONAR_GUY);
                    case CODY:
                        Locator::logger()->log(DEBUG, "Se selecciono cody.");
                        return new Accion(SELECCIONAR_CODY);
                    case HAGGAR:
                        Locator::logger()->log(DEBUG, "Se selecciono haggar.");
                        return new Accion(SELECCIONAR_HAGGAR);
                    case MAKI:
                        Locator::logger()->log(DEBUG, "Se selecciono maki.");
                        return new Accion(SELECCIONAR_MAKI);
                }
            }
        }
    } else {
        framesInactivo--;
    }
    return nullptr;
}

void EntradaMenuSeleccion::cambiarAlPersonajeSiguiente(Personaje *personajeMarcado) {
    personajeMarcado->setPersonaje(static_cast<enum PERSONAJE>((personajeMarcado->getPersonaje() + 1) % 4));
}

void EntradaMenuSeleccion::cambiarAlPersonajeAnterior(Personaje *personajeMarcado) {
    int pos = (personajeMarcado->getPersonaje() - 1) == -1 ? 3 : personajeMarcado->getPersonaje() - 1;
    personajeMarcado->setPersonaje(static_cast<enum PERSONAJE>(pos));
}

Accion *EntradaJuego::getAccion() {
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);

    ACCION accion;
    if (entrada[SDL_SCANCODE_A]) {
        accion = GOLPEAR;
    } else if (entrada[SDL_SCANCODE_S]) {
        accion = SALTAR;
    } else if (entrada[SDL_SCANCODE_D]) {
        accion = AGACHAR;
    } else if (entrada[SDL_SCANCODE_LEFT] && entrada[SDL_SCANCODE_UP]) {
        accion = CAM_IZQUIERDA_ARRIBA;
    } else if (entrada[SDL_SCANCODE_LEFT] && entrada[SDL_SCANCODE_DOWN]) {
        accion = CAM_IZQUIERDA_ABAJO;
    } else if (entrada[SDL_SCANCODE_RIGHT] && entrada[SDL_SCANCODE_UP]) {
        accion = CAM_DERECHA_ARRIBA;
    } else if (entrada[SDL_SCANCODE_RIGHT] && entrada[SDL_SCANCODE_DOWN]) {
        accion = CAM_DERECHA_ABAJO;
    } else if (entrada[SDL_SCANCODE_LEFT]) {
        accion = CAM_IZQUIERDA;
    } else if (entrada[SDL_SCANCODE_RIGHT]) {
        accion = CAM_DERECHA;
    } else if (entrada[SDL_SCANCODE_UP]) {
        accion = CAM_ARRIBA;
    } else if (entrada[SDL_SCANCODE_DOWN]) {
        accion = CAM_ABAJO;
    } else {
        accion = REPOSAR;
    }
    return new Accion(accion);
}

TrasmisionCliente::TrasmisionCliente(Socket
                                     socket, EntradaUsuario *entradaUsuario) :
        entradaUsuario(entradaUsuario),
        socket(socket) {}

EntradaUsuario *TrasmisionCliente::getEntradaUsuario() {
    std::lock_guard<std::mutex> lock(m);
    return entradaUsuario;
}

void TrasmisionCliente::setEntradaUsuario(EntradaUsuario *entradaUsuario_) {
    std::lock_guard<std::mutex> lock(m);
    entradaUsuario = entradaUsuario_;
}

void TrasmisionCliente::transmitir() {

    const size_t MS_PER_FRAME = 1.0 / Locator::configuracion()->getIntValue("/fps") * 1000; // Milisegundos.

    while (!fin) {
        size_t start = SDL_GetTicks();

        Accion *accion = getEntradaUsuario()->getAccion();
        if (accion) {
            stringstream s;
            accion->serializar(s);
            if (!socket.enviar(s)) {
                Locator::logger()->log(ERROR, "No se pudo enviar al servidor, se cierra la conexión.");
                close(socket.getIntSocket());
                break;
            }
        }

        size_t end = SDL_GetTicks();
        int sleepTime = MS_PER_FRAME + start - end;
        if (sleepTime > 0) {
            SDL_Delay(sleepTime);
        }
    }
    Locator::logger()->log(INFO, "Se termina el hilo del transmisor.");
}

pthread_t TrasmisionCliente::transmitirEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *transmision = (TrasmisionCliente *) arg;
        transmision->transmitir();
        return nullptr;
    }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de transmisión.");
    return hilo;
}

void TrasmisionCliente::finalizar() {
    fin = true;
}
