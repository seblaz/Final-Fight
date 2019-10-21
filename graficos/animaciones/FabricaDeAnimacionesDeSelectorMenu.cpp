//
// Created by sebas on 13/9/19.
//

#include "FabricaDeAnimacionesDeSelectorMenu.h"

AnimacionCliente *FabricaDeAnimacionesDeSelectorMenu::selector() {
    vector<SDL_Rect> posiciones = {
            {0, 0, 150, 215}
    };

//    vector<float> duraciones = {1};

    return new AnimacionCliente(posiciones, 2.3);
}


