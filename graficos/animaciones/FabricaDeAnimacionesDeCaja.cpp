//
// Created by sebas on 13/9/19.
//

#include "FabricaDeAnimacionesDeCaja.h"

AnimacionCliente* FabricaDeAnimacionesDeCaja::standby() {
    vector<SDL_Rect> posiciones = {
            {8, 5, 70, 120}
    };

    vector<float> duraciones = {1};
    return new AnimacionCliente(posiciones, 3);
    //return new AnimacionCliente(posiciones, duraciones, 1, 3);
}


