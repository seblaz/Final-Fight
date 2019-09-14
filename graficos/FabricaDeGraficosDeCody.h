//
// Created by sebas on 13/9/19.
//

#ifndef FINAL_FIGHT_FABRICADEGRAFICOSDECODY_H
#define FINAL_FIGHT_FABRICADEGRAFICOSDECODY_H


#include <vector>
#include "Grafico.h"
#include "GraficoDePersonaje.h"
#include "sprite/Sprite.h"

using namespace std;

class FabricaDeGraficosDeCody {

private:
    SDL_Texture *sprite;
    SDL_Renderer *renderer;
    FisicaDePersonaje *fisica;

public:
    explicit FabricaDeGraficosDeCody(SDL_Renderer *renderer, FisicaDePersonaje *fisica);

    GraficoDePersonaje caminado();
    GraficoDePersonaje saltando();
    GraficoDePersonaje parado();
};


#endif //FINAL_FIGHT_FABRICADEGRAFICOSDECODY_H
