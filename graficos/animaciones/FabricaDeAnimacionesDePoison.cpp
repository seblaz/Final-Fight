//
// Created by sebas on 13/9/19.
//

#include "FabricaDeAnimacionesDePoison.h"

Animacion* FabricaDeAnimacionesDePoison::caminando() {
    vector<SDL_Rect> posiciones = {
            {8,  6, 32, 89},
            {46,  6, 32, 89},
            {79,  8, 35, 89},
            {46,  6, 32, 89},
     };

    vector<float> duraciones = {4, 3, 4, 3};

    return new Animacion(posiciones, duraciones, 55, 4.5);
}


