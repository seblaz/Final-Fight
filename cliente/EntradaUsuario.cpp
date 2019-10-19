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
#include <SDL_events.h>
#include "../graficos/Sprite.h"

Accion *EntradaNula::getAccion() {
    return nullptr;
}

EntradaMenuSeleccion::EntradaMenuSeleccion(Entidad *entidad_) :
        entidad(entidad_) {}

Accion *EntradaMenuSeleccion::getAccion() {






    if (activo) {
        const Uint8 *entrada = SDL_GetKeyboardState(nullptr);
        enum PERSONAJE personajeMarcado = getEntidad()->getEstado<Personaje>("personajeMarcado")->getPersonaje();
        auto *renderer = Locator::renderer();
        if (entrada[SDL_SCANCODE_RETURN]) {
            activo = false;
            switch (personajeMarcado) {
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
        } else {
            if (entrada[SDL_SCANCODE_LEFT]) {
                cambiarSpriteAlAnterior(personajeMarcado);
            } else if (entrada[SDL_SCANCODE_RIGHT]) {
                cambiarAlSpriteSiguiente(personajeMarcado);
            }
        }

    }
    return nullptr;
}

void EntradaMenuSeleccion::cambiarAlSpriteSiguiente(enum PERSONAJE personajeMarcado) const {
    Configuracion *config = Locator::configuracion();
    auto *renderer = Locator::renderer();
    switch (personajeMarcado) {
        case GUY: {
            string srcSprite = config->getValue("/pantallaDeSeleccion/maki/src");
            auto *sprite = new Sprite(renderer, srcSprite);
            entidad->agregarEstado("sprite", sprite);
            entidad->agregarEstado("personajeMarcado", new Personaje(MAKI));
        }
            break;
        case CODY: {
            string srcSprite = config->getValue("/pantallaDeSeleccion/guy/src");
            auto *sprite = new Sprite(renderer, srcSprite);
            entidad->agregarEstado("sprite", sprite);
            entidad->agregarEstado("personajeMarcado", new Personaje(GUY));
        }
            break;
        case HAGGAR: {
            string srcSprite = config->getValue("/pantallaDeSeleccion/coddy/src");
            auto *sprite = new Sprite(renderer, srcSprite);
            entidad->agregarEstado("sprite", sprite);
            entidad->agregarEstado("personajeMarcado", new Personaje(CODY));
        }
            break;
        case MAKI: {
            string srcSprite = config->getValue("/pantallaDeSeleccion/haggar/src");
            auto *sprite = new Sprite(renderer, srcSprite);
            entidad->agregarEstado("sprite", sprite);
            entidad->agregarEstado("personajeMarcado", new Personaje(HAGGAR));
        }
            break;
    }
}

void EntradaMenuSeleccion::cambiarSpriteAlAnterior(enum PERSONAJE personajeMarcado) const {
    Configuracion *config = Locator::configuracion();
    auto *renderer = Locator::renderer();
    switch (personajeMarcado) {
        case GUY: {
            string srcSprite = config->getValue("/pantallaDeSeleccion/coddy/src");
            auto *sprite = new Sprite(renderer, srcSprite);
            entidad->agregarEstado("sprite", sprite);
            entidad->agregarEstado("personajeMarcado", new Personaje(CODY));
        }
            break;
        case CODY: {
            string srcSprite = config->getValue("/pantallaDeSeleccion/haggar/src");
            auto *sprite = new Sprite(renderer, srcSprite);
            entidad->agregarEstado("sprite", sprite);
            entidad->agregarEstado("personajeMarcado", new Personaje(HAGGAR));
        }
            break;
        case HAGGAR: {
            string srcSprite = config->getValue("/pantallaDeSeleccion/maki/src");
            auto *sprite = new Sprite(renderer, srcSprite);
            entidad->agregarEstado("sprite", sprite);
            entidad->agregarEstado("personajeMarcado", new Personaje(MAKI));
        }
            break;
        case MAKI: {
            string srcSprite = config->getValue("/pantallaDeSeleccion/guy/src");
            auto *sprite = new Sprite(renderer, srcSprite);
            entidad->agregarEstado("sprite", sprite);
            entidad->agregarEstado("personajeMarcado", new Personaje(GUY));
        }
            break;
    }
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
