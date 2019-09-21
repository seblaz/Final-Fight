//
// Created by sebas on 10/9/19.
//

#include "GraficoDeEscenario.h"

#include <utility>
#include <cmath>

GraficoDeEscenario::GraficoDeEscenario(FisicaDeEscenario &fisica, vector<SDL_Texture *> sprites,
                                       vector<SDL_Rect> posicionesSprite,
                                       vector<float> distanciasAlFondo, int longitudDeSprite) :
        fisica(fisica),
        sprites(std::move(sprites)),
        longitudDeSprite(longitudDeSprite),
        posicionesSprite(std::move(posicionesSprite)),
        distanciasAlFondo(std::move(distanciasAlFondo)) {}

void GraficoDeEscenario::actualizar(SDL_Renderer *renderer) {
    int alto = Locator::configuracion()->getIntValue("/resolucion/alto");
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    float escalaEnAncho = Locator::configuracion()->getFloatValue("/escala/escenario/ancho");

    for (int i = 0; i < sprites.size(); ++i) {
        SDL_Texture *sprite = sprites[i];
        SDL_Rect posicionSprite = posicionesSprite[i];
        posicionSprite.w = ancho / escalaEnAncho;
        posicionSprite.x += round(fisica.posicion() / escalaEnAncho * distanciasAlFondo[i]);
        SDL_Rect posicionEscenario = {0, 0, ancho, alto};

        SDL_RenderCopy(renderer, sprite, &posicionSprite, &posicionEscenario);
    }
}

int GraficoDeEscenario::profundidad() {
    return 230 / sin(Locator::configuracion()->getFloatValue("/escenario/inclinacion"));
}

