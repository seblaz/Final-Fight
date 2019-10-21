//
// Created by sebas on 3/10/19.
//

#include "GraficoMenuSeleccion.h"
#include "Sprite.h"
#include "../servicios/Locator.h"
#include "../modelo/Personaje.h"
#include "animaciones/Animacion.h"


void GraficoMenuSeleccion::actualizar(Entidad *entidad) {
    auto *renderer = Locator::renderer();
    auto *sprite = entidad->getEstado<Sprite>("sprite");

    SDL_RenderCopy(renderer, sprite->getTexture(), nullptr, nullptr);
    auto *personajeMarcado = entidad->getEstado<Personaje>("personajeMarcado");

    auto *selectorMenu = entidad->getEstado<Animacion>("selector_menu");
    auto *spriteSelectorMenu = entidad->getEstado<Sprite>("sprite_selector_menu");

    SDL_Rect posicionEnSpriteIndicador = selectorMenu->actualizarYDevolverPosicion();
    int xs[4] = {30, 430, 830, 1230};
    int x = xs[personajeMarcado->getPersonaje()];
    SDL_Rect posicionEnPantalla = {x, 100,
                                  int(float(posicionEnSpriteIndicador.w) * selectorMenu->escala()),
                                  int(float(posicionEnSpriteIndicador.h) * selectorMenu->escala())};
    SDL_RenderCopy(renderer, spriteSelectorMenu->getTexture(), &posicionEnSpriteIndicador, &posicionEnPantalla);
}