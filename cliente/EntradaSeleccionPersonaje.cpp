//
// Created by felipe on 12/10/19.
//


#include <SDL_keyboard.h>
#include "EntradaSeleccionPersonaje.h"
#include "../modelo/Personaje.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"

void EntradaSeleccionPersonaje::actualizar(Entidad *pantalla) {
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);
    Configuracion *config = Locator::configuracion();
    auto *renderer = Locator::renderer();

    auto *personajeMarcado = pantalla->getEstado<Personaje>("personajeMarcado");

    switch (personajeMarcado->getPersonaje()) {
        case GUY: {
            if (entrada[SDL_SCANCODE_RIGHT]) {
                string srcSprite = config->getValue("/pantallaDeSeleccion/coddy/src");
                auto *sprite = new Sprite(renderer, srcSprite);
                pantalla->agregarEstado("sprite", sprite);
                pantalla->agregarEstado("personajeMarcado", new Personaje(CODY));
            } else if (entrada[SDL_SCANCODE_LEFT]) {
                string srcSprite = config->getValue("/pantallaDeSeleccion/maki/src");
                auto *sprite = new Sprite(renderer, srcSprite);
                pantalla->agregarEstado("sprite", sprite);
                pantalla->agregarEstado("personajeMarcado", new Personaje(MAKI));
            }
        }
            break;
        case CODY: {
            if (entrada[SDL_SCANCODE_RIGHT]) {
                string srcSprite = config->getValue("/pantallaDeSeleccion/haggar/src");
                auto *sprite = new Sprite(renderer, srcSprite);
                pantalla->agregarEstado("sprite", sprite);
                pantalla->agregarEstado("personajeMarcado", new Personaje(HAGGAR));
            } else if (entrada[SDL_SCANCODE_LEFT]) {
                string srcSprite = config->getValue("/pantallaDeSeleccion/guy/src");
                auto *sprite = new Sprite(renderer, srcSprite);
                pantalla->agregarEstado("sprite", sprite);
                pantalla->agregarEstado("personajeMarcado", new Personaje(GUY));
            }
        }
            break;
        case HAGGAR: {
            if (entrada[SDL_SCANCODE_RIGHT]) {
                string srcSprite = config->getValue("/pantallaDeSeleccion/maki/src");
                auto *sprite = new Sprite(renderer, srcSprite);
                pantalla->agregarEstado("sprite", sprite);
                pantalla->agregarEstado("personajeMarcado", new Personaje(MAKI));
            } else if (entrada[SDL_SCANCODE_LEFT]) {
                string srcSprite = config->getValue("/pantallaDeSeleccion/coddy/src");
                auto *sprite = new Sprite(renderer, srcSprite);
                pantalla->agregarEstado("sprite", sprite);
                pantalla->agregarEstado("personajeMarcado", new Personaje(CODY));
            }
        }
            break;
        case MAKI: {
            if (entrada[SDL_SCANCODE_RIGHT]) {
                string srcSprite = config->getValue("/pantallaDeSeleccion/guy/src");
                auto *sprite = new Sprite(renderer, srcSprite);
                pantalla->agregarEstado("sprite", sprite);
                pantalla->agregarEstado("personajeMarcado", new Personaje(GUY));
            } else if (entrada[SDL_SCANCODE_LEFT]) {
                string srcSprite = config->getValue("/pantallaDeSeleccion/haggar/src");
                auto *sprite = new Sprite(renderer, srcSprite);
                pantalla->agregarEstado("sprite", sprite);
                pantalla->agregarEstado("personajeMarcado", new Personaje(HAGGAR));
            }
        }
            break;

    }
}