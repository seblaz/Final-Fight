//
// Created by sebas on 3/10/19.
//

#include "GraficoMenuSeleccion.h"
#include "Sprite.h"
#include "../servicios/Locator.h"
#include "../modelo/serializables/Personaje.h"
#include "AnimacionCliente.h"


void GraficoMenuSeleccion::actualizar(Entidad *entidad) {
    auto *renderer = Locator::renderer();
    auto *sprite = entidad->getEstado<Sprite>("sprite");

    SDL_RenderCopy(renderer, sprite->getTexture(), nullptr, nullptr);
    auto *personajeMarcado = entidad->getEstado<Personaje>("personaje marcado");

    auto *spriteSelectorMenu = entidad->getEstado<Sprite>("sprite selector");

    SDL_Rect posicionEnSpriteIndicador = {0, 0, 150, 215};
    int xs[4] = {30, 430, 830, 1230};
    int x = xs[personajeMarcado->getPersonaje()];
    SDL_Rect posicionEnPantalla = {x, 100,
                                   int(float(posicionEnSpriteIndicador.w) * 2.3),
                                   int(float(posicionEnSpriteIndicador.h) * 2.3)};

    SDL_RenderCopy(renderer, spriteSelectorMenu->getTexture(), &posicionEnSpriteIndicador, &posicionEnPantalla);


}