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

Accion *EntradaNula::getAccion() {
    return nullptr;
}

EntradaMenuSeleccion::EntradaMenuSeleccion(enum PERSONAJE personajeSeleccionado_) :
        personajeSeleccionado(personajeSeleccionado_)
        {}

Accion *EntradaMenuSeleccion::getAccion() {
    if (activo) {
        const Uint8 *entrada = SDL_GetKeyboardState(nullptr);

        if (entrada[SDL_SCANCODE_RETURN]){
            activo = false;
            switch (getPersonajeSeleccionado()){
                case GUY:
                    return new Accion(SELECCIONAR_GUY);
                case CODY:
                    return new Accion(SELECCIONAR_CODY);
                case HAGGAR:
                    return new Accion(SELECCIONAR_HAGGAR);
                case MAKI:
                    return new Accion(SELECCIONAR_MAKI);
            };
        }

    }
    return nullptr;
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

TrasmisionCliente::TrasmisionCliente(Socket socket, EntradaUsuario *entradaUsuario) :
        entradaUsuario(entradaUsuario),
        socket(socket) {}

EntradaUsuario *TrasmisionCliente::getEntradaUsuario() {
    std::lock_guard<std::mutex> lock(m);
    return entradaUsuario;
}

void TrasmisionCliente::setEntradaUsuario(EntradaUsuario *entradaUsuario_) {
    std::lock_guard<std::mutex> lock(m);
    entradaUsuario = entradaUsuario_;
}ll

void TrasmisionCliente::transmitir() {

    const size_t MS_PER_FRAME = 1.0 / Locator::configuracion()->getIntValue("/fps") * 1000; // Milisegundos.

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wmissing-noreturn"
    while (true) {
        size_t start = SDL_GetTicks();

        Accion *accion = getEntradaUsuario()->getAccion();
        if (accion) {
            stringstream s;
            accion->serializar(s);
            socket.enviar(s);
        }

        size_t end = SDL_GetTicks();
        int sleepTime = MS_PER_FRAME + start - end;
        if (sleepTime > 0) {
            SDL_Delay(sleepTime);
        }
    }
#pragma clang diagnostic pop
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
