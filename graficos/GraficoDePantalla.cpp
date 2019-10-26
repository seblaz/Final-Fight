//
// Created by felipe on 26/10/19.
//

#include "GraficoDePantalla.h"
#include "../servicios/Configuracion.h"
#include "../servicios/Locator.h"

void GraficoDePantalla::graficarPantalla(const string& pathConfigSrcFondo){
    Configuracion *config = Locator::configuracion();
    SDL_Renderer *renderer_ = Locator::renderer();
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    int alto = Locator::configuracion()->getIntValue("/resolucion/alto");
    auto *spritePantallaIngreso = Locator::fabricaDeSprites()->getSpriteConfigPath(pathConfigSrcFondo);

    SDL_Rect posicionEnPantallaIngreso = {0, 0, ancho, alto};
    SDL_RenderCopy(renderer_, spritePantallaIngreso->getTexture(), nullptr, &posicionEnPantallaIngreso);
    SDL_RenderPresent(renderer_);
};
