//
// Created by sebas on 2/11/19.
//

#include "PantallaError.h"
#include "../../../servicios/Locator.h"

#include <utility>

PantallaError::PantallaError(IdPantalla id, string configPath) :
        Pantalla(std::move(id)), configPath(std::move(configPath)) {}

void PantallaError::actualizar(SDL_Event *e) {
    SDL_Renderer *renderer = Locator::renderer();

    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    int alto = Locator::configuracion()->getIntValue("/resolucion/alto");

    auto *spritePantallaIngreso = Locator::fabricaDeSprites()->getSpriteConfigPath(configPath);

    SDL_Rect posicionEnPantallaIngreso = {0, 0, ancho, alto};
    SDL_RenderCopy(renderer, spritePantallaIngreso->getTexture(), nullptr, &posicionEnPantallaIngreso);
}
