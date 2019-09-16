//
// Created by sebas on 13/9/19.
//

#include "FabricaDeAnimacionesDePoison.h"

Animacion* FabricaDeAnimacionesDePoison::caminando() {
    vector<SDL_Rect> posiciones = {
            {0,  3, 47, 100},
            {40,  3, 40, 100},
            {77,  3, 40, 100},
    };

    vector<float> duraciones = {1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}


