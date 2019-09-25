//
// Created by sebas on 13/9/19.
//

#include "FabricaDeAnimacionesDeTubo.h"

Animacion* FabricaDeAnimacionesDeTubo::standby() {
    vector<SDL_Rect> posiciones = {
            {0, 0, 68, 15}
    };

    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 1, 3);
}


