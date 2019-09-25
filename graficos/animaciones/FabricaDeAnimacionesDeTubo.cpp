//
// Created by sebas on 13/9/19.
//

#include "FabricaDeAnimacionesDeTubo.h"

Animacion* FabricaDeAnimacionesDeTubo::standby() {
    vector<SDL_Rect> posiciones = {
            {0, 5, 68, 8}
    };

    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 1, 3);
}


