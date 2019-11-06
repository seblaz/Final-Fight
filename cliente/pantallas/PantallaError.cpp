//
// Created by sebas on 2/11/19.
//

#include "PantallaError.h"
#include "../../servicios/Locator.h"

#include <utility>

PantallaError::PantallaError(IdPantalla id, string configPath) :
        configPath(std::move(configPath)),
        Pantalla(std::move(id), nullptr, nullptr, nullptr) {}

void PantallaError::graficar(SDL_Renderer *renderer) {
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    int alto = Locator::configuracion()->getIntValue("/resolucion/alto");

    auto *spritePantallaIngreso = Locator::fabricaDeSprites()->getSpriteConfigPath(configPath);

    SDL_Rect posicionEnPantallaIngreso = {0, 0, ancho, alto};
    SDL_RenderCopy(renderer, spritePantallaIngreso->getTexture(), nullptr, &posicionEnPantallaIngreso);
}