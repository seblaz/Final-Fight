//
// Created by felipe on 12/10/19.
//


#include <SDL_keyboard.h>
#include <SDL_events.h>
#include "EntradaSeleccionPersonaje.h"
#include "../modelo/Personaje.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"

void EntradaSeleccionPersonaje::actualizar(Entidad *pantalla) {
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);
    Configuracion *config = Locator::configuracion();
    auto *renderer = Locator::renderer();

    auto *personajeMarcado = pantalla->getEstado<Personaje>("personajeMarcado");

    SDL_Event e;
    while (SDL_PollEvent(&e)) {
        switch (e.type) {
            case SDL_KEYDOWN:
                switch (e.key.keysym.sym) {
                    case SDLK_LEFT: {
                        switch (personajeMarcado->getPersonaje()) {
                            case GUY: {
                                string srcSprite = config->getValue("/pantallaDeSeleccion/maki/src");
                                auto *sprite = new Sprite(renderer, srcSprite);
                                pantalla->agregarEstado("sprite", sprite);
                                pantalla->agregarEstado("personajeMarcado", new Personaje(MAKI));
                            }
                                break;
                            case CODY: {
                                string srcSprite = config->getValue("/pantallaDeSeleccion/guy/src");
                                auto *sprite = new Sprite(renderer, srcSprite);
                                pantalla->agregarEstado("sprite", sprite);
                                pantalla->agregarEstado("personajeMarcado", new Personaje(GUY));
                            }
                                break;
                            case HAGGAR: {
                                string srcSprite = config->getValue("/pantallaDeSeleccion/coddy/src");
                                auto *sprite = new Sprite(renderer, srcSprite);
                                pantalla->agregarEstado("sprite", sprite);
                                pantalla->agregarEstado("personajeMarcado", new Personaje(CODY));
                            }
                                break;
                            case MAKI: {
                                string srcSprite = config->getValue("/pantallaDeSeleccion/haggar/src");
                                auto *sprite = new Sprite(renderer, srcSprite);
                                pantalla->agregarEstado("sprite", sprite);
                                pantalla->agregarEstado("personajeMarcado", new Personaje(HAGGAR));
                            }
                                break;
                        }
                    }
                        break;
                    case SDLK_RIGHT: {
                        switch (personajeMarcado->getPersonaje()) {
                            case GUY: {
                                string srcSprite = config->getValue("/pantallaDeSeleccion/coddy/src");
                                auto *sprite = new Sprite(renderer, srcSprite);
                                pantalla->agregarEstado("sprite", sprite);
                                pantalla->agregarEstado("personajeMarcado", new Personaje(CODY));
                            }
                                break;
                            case CODY: {
                                string srcSprite = config->getValue("/pantallaDeSeleccion/haggar/src");
                                auto *sprite = new Sprite(renderer, srcSprite);
                                pantalla->agregarEstado("sprite", sprite);
                                pantalla->agregarEstado("personajeMarcado", new Personaje(HAGGAR));
                            }
                                break;
                            case HAGGAR: {
                                string srcSprite = config->getValue("/pantallaDeSeleccion/maki/src");
                                auto *sprite = new Sprite(renderer, srcSprite);
                                pantalla->agregarEstado("sprite", sprite);
                                pantalla->agregarEstado("personajeMarcado", new Personaje(MAKI));
                            }
                                break;
                            case MAKI: {
                                string srcSprite = config->getValue("/pantallaDeSeleccion/guy/src");
                                auto *sprite = new Sprite(renderer, srcSprite);
                                pantalla->agregarEstado("sprite", sprite);
                                pantalla->agregarEstado("personajeMarcado", new Personaje(GUY));
                            }
                                break;
                        }
                        break;
                    }
                }
                break;
            case SDL_QUIT:{
                exit(1);
            }
        }

    }
}

