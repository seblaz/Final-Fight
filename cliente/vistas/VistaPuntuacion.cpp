//
// Created by sebas on 7/11/19.
//

#include "VistaPuntuacion.h"
#include "../../servicios/Locator.h"

VistaPuntuacion::VistaPuntuacion(PuntuacionJugadores *puntuaciones) :
        puntuaciones(puntuaciones) {}

void VistaPuntuacion::graficar(SDL_Renderer *renderer) {
    Configuracion *config = Locator::configuracion();
    int ancho = config->getIntValue("/resolucion/ancho");
    int alto = config->getIntValue("/resolucion/alto");

    auto *fondo = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallas/autenticacion/fondo/src");

    SDL_Rect posicionEnPantallaCompleta = {0, 0, ancho, alto};
    SDL_RenderCopy(renderer, fondo->getTexture(), nullptr, &posicionEnPantallaCompleta);
}
