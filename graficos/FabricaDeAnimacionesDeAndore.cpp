//
// Created by sebas on 14/9/19.
//

#include "FabricaDeAnimacionesDeAndore.h"

Animacion* FabricaDeAnimacionesDeAndore::caminado() {
    vector<SDL_Rect> posiciones = {
            //{10, 5, 55, 110},
            {62, 5, 50, 110},
            {111, 5, 50, 110},
            //{10, 5, 55, 110},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeAndore::saltando() {
    vector<SDL_Rect> posiciones = {{10, 5, 55, 110}};

    vector<float> duraciones = {1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeAndore::parado() {
    vector<SDL_Rect> posiciones = {{10, 5, 55, 110}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion *FabricaDeAnimacionesDeAndore::agachado() {
    vector<SDL_Rect> posiciones = {{10, 5, 55, 110}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeAndore::golpear() {
    vector<SDL_Rect> posiciones = {
            {10, 120, 70, 110},
            {85, 120, 75, 110},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}