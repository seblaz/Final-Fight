//
// Created by sebas on 13/9/19.
//

#include "FabricaDeAnimacionesDePoison.h"

Animacion* FabricaDeAnimacionesDePoison::caminando() {
    vector<SDL_Rect> posiciones = {
            {6,  4, 37, 91},
            {48,  5, 30, 90},
            {78,  5, 35, 91},
            {48,  5, 30, 90},
    };

    vector<float> duraciones = {4, 3, 4, 3};

    return new Animacion(posiciones, duraciones, 55, 4.5);
}


