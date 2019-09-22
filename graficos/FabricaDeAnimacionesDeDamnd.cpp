//
// Created by sebas on 14/9/19.
//

#include "FabricaDeAnimacionesDeDamnd.h"

Animacion* FabricaDeAnimacionesDeDamnd::caminado() {
    vector<SDL_Rect> posiciones = {
            {292, 0, 88, 120},
            {392, 0, 88, 120},
            {515, 0, 88, 120},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeDamnd::saltando() {
    vector<SDL_Rect> posiciones = {
            {100, 150, 70, 100},
            {205, 170, 85, 100},
            {295, 170, 85, 100},
            {380, 170, 85, 100},
            {515, 160, 90, 100},
            {515, 160, 90, 100},
    };

    vector<float> duraciones = {1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeDamnd::parado() {
    vector<SDL_Rect> posiciones = {{5, 10, 85, 120}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion *FabricaDeAnimacionesDeDamnd::agachado() {
    vector<SDL_Rect> posiciones = {{5, 10, 85, 120}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeDamnd::golpear() {
    vector<SDL_Rect> posiciones = {
            {605, 20, 98, 120},
            {705, 20, 95, 120},
            {805, 20, 95, 120},
            {905, 20, 130, 120},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}