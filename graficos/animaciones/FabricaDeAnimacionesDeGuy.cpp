#include "FabricaDeAnimacionesDeGuy.h"

Animacion* FabricaDeAnimacionesDeGuy::caminando() {
    vector<SDL_Rect> posiciones = {
            {5, 100, 35, 95},
            {40, 100, 45, 95},
            {85, 100, 45, 95},
            {125, 100, 45, 95},
            {170, 100, 45, 95},
            {220, 100, 35, 95},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeGuy::saltando() {
    vector<SDL_Rect> posiciones = {
            {5, 205, 50, 90},
            {55, 195, 50, 100},
            {55, 195, 50, 100},
            {5, 205, 50, 90},
    };

    vector<float> duraciones = {1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeGuy::reposando() {
    vector<SDL_Rect> posiciones = {{5, 0, 55, 95}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion *FabricaDeAnimacionesDeGuy::agachado() {
    vector<SDL_Rect> posiciones = {{343, 670, 50, 90}};
    vector<float> duraciones = {1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion* FabricaDeAnimacionesDeGuy::golpear() {
    vector<SDL_Rect> posiciones = {
            //{6, 380, 51, 100},
            //{5, 0, 55, 95},
            //{60, 380, 65, 100},
            //{122, 380, 63, 100},
            {5, 205, 50, 90},
            {185, 380, 70, 100},
            //{260, 380, 70, 100},
            //{330, 380, 70, 100},
            /*{395, 380, 60, 100},
            {448, 380, 50, 100},
            {497, 380, 50, 100},
            {540, 370, 58, 105},
            {600, 380, 58, 100},*/
    };

    vector<float> duraciones = {1, 2, 1};

    return new Animacion(posiciones, duraciones, 16, 4.5);
}

Animacion *FabricaDeAnimacionesDeGuy::saltandoAdelante() {
    vector<SDL_Rect> posiciones = {
            {5, 195, 50, 90},
            {55, 195, 50, 100},
            {105, 192, 60, 95},
            {165, 192, 48, 90},
            {210, 192, 65, 90},
            {280, 192, 65, 90},

    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion *FabricaDeAnimacionesDeGuy::patadaBasica() {
    vector<SDL_Rect> posiciones = {
            //{155, 500, 45, 80},
            {200, 500, 85, 80},
    };

    vector<float> duraciones = {1, 1, 3, 2};

    return new Animacion(posiciones, duraciones, 35, 4.5);
}