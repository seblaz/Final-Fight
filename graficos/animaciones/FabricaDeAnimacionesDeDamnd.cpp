//
// Created by sebas on 14/9/19.
//

#include "FabricaDeAnimacionesDeDamnd.h"

Animacion* FabricaDeAnimacionesDeDamnd::caminando() {
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

Animacion* FabricaDeAnimacionesDeDamnd::reposando() {
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

Animacion *FabricaDeAnimacionesDeDamnd::saltandoAdelante() {
    vector<SDL_Rect> posiciones = {
            {16,  238, 39, 81},
            {115, 218, 47, 74},
            {245,  240, 60, 60},
            {305,  220, 60, 106},
            {367, 240, 60, 83},
            {433, 225, 50, 78},
            {115, 218, 47, 74},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion *FabricaDeAnimacionesDeDamnd::patadaBasica() {
    vector<SDL_Rect> posiciones = {
            {245,  540, 60, 80},
            {315,  540, 50, 81},
            {360,  560, 85, 81},
            {315,  540, 50, 81},
    };

    vector<float> duraciones = {1, 1, 3, 2};

    return new Animacion(posiciones, duraciones, 35, 4.5);
}