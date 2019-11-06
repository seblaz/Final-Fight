//
// Created by sebas on 6/11/19.
//

#include "VistaMenuSeleccion.h"

VistaMenuSeleccion::VistaMenuSeleccion(MenuSeleccion *menu) :
        menu(menu) {}

void VistaMenuSeleccion::graficar(SDL_Renderer *renderer) {

    SDL_Rect posicionEnSpriteIndicador = {0, 0, 150, 215};
    int xs[4] = {30, 430, 830, 1230};
    int x = xs[static_cast<int>(menu->getPersonaje())];
    SDL_Rect posicionEnPantalla = {x, 100,
                                   int(float(posicionEnSpriteIndicador.w) * 2.3),
                                   int(float(posicionEnSpriteIndicador.h) * 2.3)};

    SDL_RenderCopy(renderer, fondo->getTexture(), nullptr, nullptr);
    Sprite *sprite = menu->listo() ? confirmacion : selector;
    SDL_RenderCopy(renderer, sprite->getTexture(), &posicionEnSpriteIndicador, &posicionEnPantalla);
}
