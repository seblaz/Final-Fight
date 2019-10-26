//
// Created by felipe on 26/10/19.
//

#include "PantallaErrorDeConexion.h"
#include "../servicios/Locator.h"

void PantallaErrorDeConexion::graficarPantallaDeErrorDeConexion() {

    Configuracion *config = Locator::configuracion();
    SDL_Renderer *renderer_ = Locator::renderer();
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    int alto = Locator::configuracion()->getIntValue("/resolucion/alto");
    SDL_Rect posicionEnPantallaIngreso = {0, 0, ancho, alto};
    auto *spritePantallaIngreso = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallaErrorDeConexion/src");
    SDL_RenderCopy(renderer_, spritePantallaIngreso->getTexture(), nullptr, &posicionEnPantallaIngreso);
    SDL_RenderPresent(renderer_); // Update screen

}