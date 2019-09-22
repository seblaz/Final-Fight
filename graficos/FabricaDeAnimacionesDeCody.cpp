#include "FabricaDeAnimacionesDeCody.h"

Animacion* FabricaDeAnimacionesDeCody::caminado() {
    vector<SDL_Rect> posiciones = {
            {10,  100, 29, 90},
            {51,  100, 47, 90},
            {113, 100, 43, 90},
            {164, 100, 27, 90},
            {212, 100, 47, 90},
            {266, 100, 47, 90},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeCody::saltando() {
    vector<SDL_Rect> posiciones = {
            {16,  238, 39, 81},
            {74,  203, 32, 106},
            {177, 220, 53, 83},
            {115, 218, 47, 74},
    };

    vector<float> duraciones = {1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeCody::parado() {
    vector<SDL_Rect> posiciones = {{5, 6, 39, 90}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion *FabricaDeAnimacionesDeCody::agachado() {
    vector<SDL_Rect> posiciones = {{350, 715, 39, 90}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeCody::golpear() {
    vector<SDL_Rect> posiciones = {
            {10, 420, 48, 104}, //104 , 67 ancho_
            {63, 420, 65, 104},
            {130, 420, 65, 104},
            {195, 420, 78, 104},
            {274, 420, 73, 104},
            {340, 420, 70, 104},
            {408, 420, 65, 104},
            {475, 420, 60, 104},
            //{475, 420, 60, 104},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}