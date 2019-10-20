//
// Created by felipe on 12/10/19.
//

#include <SDL_keyboard.h>
#include "EntradaSeleccionPersonaje.h"
#include "../modelo/Personaje.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"

void EntradaSeleccionPersonaje::actualizar(Entidad *pantalla) {
    auto *personajeMarcado = pantalla->getEstado<Personaje>("personajeMarcado");
    if (framesInactivo == 0) {
        if (activo) {
            const Uint8 *entrada = SDL_GetKeyboardState(nullptr);
            if (entrada[SDL_SCANCODE_LEFT]) {
                cambiarAlPersonajeAnterior(pantalla, personajeMarcado);
            } else if (entrada[SDL_SCANCODE_RIGHT]) {
                cambiarAlPersonajeSiguiente(pantalla, personajeMarcado);
            } else if (entrada[SDL_SCANCODE_RETURN]) {
                Locator::logger()->log(DEBUG, "Se selecciono enter");
                activo = false;
            }
            framesInactivo = framesPorAccion;
        }
    } else {
        framesInactivo--;
    }
}

void EntradaSeleccionPersonaje::cambiarAlPersonajeSiguiente(Entidad *pantalla, Personaje *personajeMarcado) {
    switch (personajeMarcado->getPersonaje()) {
        case GUY: {
            Locator::logger()->log(INFO, "Se marco a cody");
            pantalla->agregarEstado("personajeMarcado", new Personaje(CODY));
        }
            break;
        case CODY: {
            Locator::logger()->log(INFO, "Se marco a haggar");
            pantalla->agregarEstado("personajeMarcado", new Personaje(HAGGAR));
        }
            break;
        case HAGGAR: {
            Locator::logger()->log(INFO, "Se marco a maki");
            pantalla->agregarEstado("personajeMarcado", new Personaje(MAKI));
        }
            break;
        case MAKI: {
            Locator::logger()->log(INFO, "Se marco a guy");
            pantalla->agregarEstado("personajeMarcado", new Personaje(GUY));
        }
            break;
    }
}

void EntradaSeleccionPersonaje::cambiarAlPersonajeAnterior(Entidad *pantalla, Personaje *personajeMarcado) {
    switch (personajeMarcado->getPersonaje()) {
        case GUY: {
            Locator::logger()->log(INFO, "Se marco a maki");
            pantalla->agregarEstado("personajeMarcado", new Personaje(MAKI));
        }
            break;
        case CODY: {
            Locator::logger()->log(INFO, "Se marco a guy");
            pantalla->agregarEstado("personajeMarcado", new Personaje(GUY));
        }
            break;
        case HAGGAR: {
            Locator::logger()->log(INFO, "Se marco a cody");
            pantalla->agregarEstado("personajeMarcado", new Personaje(CODY));
        }
            break;
        case MAKI: {
            Locator::logger()->log(INFO, "Se marco a haggar");
            pantalla->agregarEstado("personajeMarcado", new Personaje(HAGGAR));
        }
            break;
    }
}

