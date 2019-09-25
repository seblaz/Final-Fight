//
// Created by sebas on 13/9/19.
//

#include "FabricaDeAnimacionesDeNeumatico.h"

Animacion* FabricaDeAnimacionesDeNeumatico::standby() {
    vector<SDL_Rect> posiciones = {
            {8, 5, 70, 120}
    };

    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 1, 3);
}


