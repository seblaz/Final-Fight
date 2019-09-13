//
// Created by sebas on 13/9/19.
//

#ifndef FINAL_FIGHT_ANIMACION_H
#define FINAL_FIGHT_ANIMACION_H


#include <SDL_rect.h>
#include <vector>

using namespace std;

class Animacion {

private:
    vector<SDL_Rect> posiciones;
    vector<float> duracionesPorSprite;
    int duracionTotal;

    int framesFaltantes;
    int spriteActual;
    const float sumaDeDuracionesRelativas;

    int calcularFramesFaltantes();

public:
    Animacion(vector<SDL_Rect> posiciones, vector<float> duracionesPorSprite, int duracionTotal);
    SDL_Rect actualizarYDevolverPosicion();
};


#endif //FINAL_FIGHT_ANIMACION_H
