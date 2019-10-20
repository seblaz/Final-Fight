//
// Created by sebas on 3/10/19.
//

#include "GraficoDePantallaCompleta.h"
#include "Sprite.h"
#include "../servicios/Locator.h"
#include "../modelo/Personaje.h"
#include "animaciones/Animacion.h"


void GraficoDePantallaCompleta::actualizar(Entidad *entidad) {
    auto *renderer = Locator::renderer();
    auto *sprite = entidad->getEstado<Sprite>("sprite");

    SDL_RenderCopy(renderer, sprite->getTexture(), nullptr, nullptr);
    auto *personajeMarcado = entidad->getEstado<Personaje>("personajeMarcado");

    if (personajeMarcado != nullptr) {

        auto *selectorMenu = entidad->getEstado<Animacion>("selector_menu");
        auto *spriteSelectorMenu = entidad->getEstado<Sprite>("sprite_selector_menu");

        SDL_Rect posicionEnSpriteIndicador = selectorMenu->actualizarYDevolverPosicion();

        switch (personajeMarcado->getPersonaje()) {
            case GUY: {
                SDL_Rect posicionEnPantalla = {30,
                                               100,
                                               int(posicionEnSpriteIndicador.w * selectorMenu->escala()),
                                               int(posicionEnSpriteIndicador.h * selectorMenu->escala())};

                SDL_RenderCopy(renderer, spriteSelectorMenu->getTexture(), &posicionEnSpriteIndicador,
                               &posicionEnPantalla);
            }
                break;
            case CODY: {
                SDL_Rect posicionEnPantalla = {430,
                                               100,
                                               int(posicionEnSpriteIndicador.w * selectorMenu->escala()),
                                               int(posicionEnSpriteIndicador.h * selectorMenu->escala())};

                SDL_RenderCopy(renderer, spriteSelectorMenu->getTexture(), &posicionEnSpriteIndicador,
                               &posicionEnPantalla);
            }
                break;
            case HAGGAR: {
                SDL_Rect posicionEnPantalla = {830,
                                               100,
                                               int(posicionEnSpriteIndicador.w * selectorMenu->escala()),
                                               int(posicionEnSpriteIndicador.h * selectorMenu->escala())};

                SDL_RenderCopy(renderer, spriteSelectorMenu->getTexture(), &posicionEnSpriteIndicador,
                               &posicionEnPantalla);
            }
                break;
            case MAKI: {
                SDL_Rect posicionEnPantalla = {1230,
                                               100,
                                               int(posicionEnSpriteIndicador.w * selectorMenu->escala()),
                                               int(posicionEnSpriteIndicador.h * selectorMenu->escala())};

                SDL_RenderCopy(renderer, spriteSelectorMenu->getTexture(), &posicionEnSpriteIndicador,
                               &posicionEnPantalla);
            }
                break;
        }
    }
}