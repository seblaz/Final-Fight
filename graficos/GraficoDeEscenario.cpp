//
// Created by sebas on 10/9/19.
//

#include "GraficoDeEscenario.h"

#include <utility>
#include <cmath>

GraficoDeEscenario::GraficoDeEscenario(FisicaDeEscenario &fisica, vector<SDL_Texture *> sprites,
                                       vector<SDL_Rect> posicionesSprite,
                                       vector<float> distanciasAlFondo) :
        fisica(fisica),
        sprites(std::move(sprites)),
        posicionesSprite(std::move(posicionesSprite)),
        distanciasAlFondo(std::move(distanciasAlFondo)) {}

void GraficoDeEscenario::actualizar(SDL_Renderer *renderer) {
    int alto = Locator::configuracion()->alturaDePantalla;
    int ancho = Locator::configuracion()->anchoDePantalla;

    for (int i = 0; i < sprites.size(); ++i) {
        SDL_Texture *sprite = sprites[i];
        SDL_Rect posicionSprite = posicionesSprite[i];
        posicionSprite.x += round(fisica.posicion() * posicionSprite.w / ancho * distanciasAlFondo[i]);
        SDL_Rect posicionEscenario = {0, 0, ancho, alto};

        SDL_RenderCopy(renderer, sprite, &posicionSprite, &posicionEscenario);
    }
}

