//
// Created by sebas on 13/9/19.
//

#ifndef FINAL_FIGHT_FABRICADEGRAFICOSDEPOISON_H
#define FINAL_FIGHT_FABRICADEGRAFICOSDEPOISON_H


#include <vector>
#include "Grafico.h"
#include "GraficoDePersonaje.h"
#include "sprite/Sprite.h"

using namespace std;

class FabricaDeGraficosDePoison {

private:
    SDL_Texture *sprite;
    SDL_Renderer *renderer;

public:
    explicit FabricaDeGraficosDePoison(SDL_Renderer *renderer);

    GraficoDePersonaje caminado();

};


#endif //FINAL_FIGHT_FABRICADEGRAFICOSDEPOISON_H
