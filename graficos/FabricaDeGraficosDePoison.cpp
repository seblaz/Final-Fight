//
// Created by sebas on 13/9/19.
//

#include "FabricaDeGraficosDePoison.h"
#include "Animacion.h"

FabricaDeGraficosDePoison::FabricaDeGraficosDePoison(SDL_Renderer *renderer) :
        renderer(renderer) {
    sprite = Sprite(renderer, "assets/personajes/poisson.png").getTexture();
}

GraficoDePersonaje FabricaDeGraficosDePoison::caminado() {
    vector<SDL_Rect> posiciones = {
           {0,  3, 47, 100},
            {40,  3, 40, 100},
           {77,  3, 40, 100},
    };

    vector<float> duraciones = {1, 1, 1, 1};

    Animacion animacion(posiciones, duraciones, 60);
    GraficoDePersonaje graficoDePersonaje(renderer, sprite, animacion);
    return graficoDePersonaje;
}
