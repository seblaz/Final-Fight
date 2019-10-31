//
// Created by felipe on 26/10/19.
//

#include "GraficoDePantalla.h"
#include "../servicios/Configuracion.h"
#include "../servicios/Locator.h"

void GraficoDePantalla::graficarPantalla(const string& pathConfigSrcFondo){

    SDL_Renderer *renderer = Locator::renderer();

    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    int alto = Locator::configuracion()->getIntValue("/resolucion/alto");

    auto *spritePantallaIngreso = Locator::fabricaDeSprites()->getSpriteConfigPath(pathConfigSrcFondo);

    SDL_Rect posicionEnPantallaIngreso = {0, 0, ancho, alto};
    SDL_RenderCopy(renderer, spritePantallaIngreso->getTexture(), nullptr, &posicionEnPantallaIngreso);
//    SDL_RenderPresent(renderer);
};
