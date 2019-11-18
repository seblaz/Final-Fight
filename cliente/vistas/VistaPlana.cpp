//
// Created by sebas on 18/11/19.
//

#include "VistaPlana.h"
#include "../../servicios/Locator.h"

#include <utility>

VistaPlana::VistaPlana(string configFondo, string configMusica) :
        configFondo(std::move(configFondo)),
        configMusica(std::move(configMusica)) {}

void VistaPlana::graficar(SDL_Renderer *renderer) {
    Configuracion *config = Locator::configuracion();
    int ancho = config->getIntValue("/resolucion/ancho");
    int alto = config->getIntValue("/resolucion/alto");

    auto *fondo = Locator::fabricaDeSprites()->getSpriteConfigPath(configFondo);

    SDL_Rect posicionEnPantallaCompleta = {0, 0, ancho, alto};
    SDL_RenderCopy(renderer, fondo->getTexture(), nullptr, &posicionEnPantallaCompleta);
}

string VistaPlana::getConfigPathMusica() {
    return configMusica;
}
