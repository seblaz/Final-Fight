//
// Created by sebas on 14/9/19.
//

#include "FabricaDeAnimacionesDeOriber.h"

Animacion* FabricaDeAnimacionesDeOriber::caminado() {
    vector<SDL_Rect> posiciones = {
            {3, 5, 60, 90},
            {63, 2, 60, 93},
            {123, 5, 60, 90},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeOriber::saltando() {
    vector<SDL_Rect> posiciones = {{250, 75, 60, 90}};

    vector<float> duraciones = {1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeOriber::parado() {
    vector<SDL_Rect> posiciones = {{250, 75, 60, 90}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion *FabricaDeAnimacionesDeOriber::agachado() {
    vector<SDL_Rect> posiciones = {{250, 75, 60, 90}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeOriber::golpear() {
    vector<SDL_Rect> posiciones = {{310, 72, 75, 93}};

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}