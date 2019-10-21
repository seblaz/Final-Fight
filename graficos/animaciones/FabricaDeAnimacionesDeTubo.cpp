//
// Created by sebas on 13/9/19.
//

#include "FabricaDeAnimacionesDeTubo.h"

AnimacionCliente* FabricaDeAnimacionesDeTubo::standby() {
    vector<SDL_Rect> posiciones = {
            {0, 5, 68, 8}
    };

    //vector<float> duraciones = {1};
    return new AnimacionCliente(posiciones, 3);
    //return new AnimacionCliente(posiciones, duraciones, 1, 3);
}


