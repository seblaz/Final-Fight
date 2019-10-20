//
// Created by sebas on 13/9/19.
//

#include "FabricaDeAnimacionesDeIndicador.h"

Animacion* FabricaDeAnimacionesDeIndicador::indicador() {
    vector<SDL_Rect> posiciones = {
            {0, 0, 51, 44}
    };

    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 1, 1.5);
}


