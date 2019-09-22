//
// Created by sebas on 13/9/19.
//

#include "FabricaDeAnimacionesDePoison.h"

Animacion* FabricaDeAnimacionesDePoison::caminando() {
    vector<SDL_Rect> posiciones = {
            {6,  4, 37, 91},
            {48,  5, 30, 90},
            {78,  5, 35, 91},
    };

    vector<float> duraciones = {1, 1, 1};

    return new Animacion(posiciones, duraciones, 30, 4.5);
}


