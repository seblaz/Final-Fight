//
// Created by sebas on 8/11/19.
//

#include "VistaFin.h"
#include "../../servicios/Locator.h"

void VistaFin::graficar(SDL_Renderer *renderer) {
    Configuracion *config = Locator::configuracion();
    int ancho = config->getIntValue("/resolucion/ancho");
    int alto = config->getIntValue("/resolucion/alto");

    auto *fondo = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/fin/src");

    SDL_Rect posicionEnPantallaCompleta = {0, 0, ancho, alto};
    SDL_RenderCopy(renderer, fondo->getTexture(), nullptr, &posicionEnPantallaCompleta);
}
