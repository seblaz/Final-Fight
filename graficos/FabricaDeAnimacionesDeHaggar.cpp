//
// Created by sebas on 14/9/19.
//

#include "FabricaDeAnimacionesDeHaggar.h"

Animacion* FabricaDeAnimacionesDeHaggar::caminado() {
    vector<SDL_Rect> posiciones = {
            {0,  103, 60, 104},
            {65,  103, 60, 104},
            {135, 100, 60, 104},
            {204, 103, 60, 104},
            {275, 100, 60, 104},
            {340, 100, 60, 104},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeHaggar::saltando() {
    vector<SDL_Rect> posiciones = {
            {5,  212, 60, 104},
            {65,  212, 60, 104},
            {115, 205, 60, 104},
            {65,  212, 60, 104},
            {5,  212, 60, 104},
    };

    vector<float> duraciones = {1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeHaggar::parado() {
    vector<SDL_Rect> posiciones = {{0, 0, 64, 104}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion *FabricaDeAnimacionesDeHaggar::agachado() {
    vector<SDL_Rect> posiciones = {{360, 825, 60, 104}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeHaggar::golpear() {
    vector<SDL_Rect> posiciones = {
            {10, 440, 48, 90},
            {58, 440, 65, 90},
            {113, 440, 97, 90},
            {203, 437, 60, 95},
            {260, 440, 60, 95},
            {320, 440, 85, 90},
            //{408, 420, 65, 104},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}