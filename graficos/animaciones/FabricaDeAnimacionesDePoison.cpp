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

Animacion *FabricaDeAnimacionesDePoison::saltando() {
    vector<SDL_Rect> posiciones = {
            {8,  6, 32, 89},
            {79,  8, 35, 89},
    };

    vector<float> duraciones = {1, 1};

    return new Animacion(posiciones, duraciones, 55, 4.5);
}

Animacion *FabricaDeAnimacionesDePoison::reposando() {
    return nullptr;
}

Animacion *FabricaDeAnimacionesDePoison::agachado() {
    vector<SDL_Rect> posiciones = {
            {79,  8, 35, 89},
    };

    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 55, 4.5);
}

Animacion *FabricaDeAnimacionesDePoison::golpear() {
    return nullptr;
}

Animacion *FabricaDeAnimacionesDePoison::saltandoAdelante() {
    vector<SDL_Rect> posiciones = {
            {6,  257, 40, 67},
            {49,  232, 77, 68},
            {129,  215, 36, 70},
            {169,  216, 60, 45},
            {236,  199, 36, 69},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 45, 4.5);
}

Animacion *FabricaDeAnimacionesDePoison::patadaBasica() {
    return nullptr;
}


