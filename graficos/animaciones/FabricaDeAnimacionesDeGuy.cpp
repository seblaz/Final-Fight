#include "FabricaDeAnimacionesDeGuy.h"

AnimacionCliente* FabricaDeAnimacionesDeGuy::caminando() {
    vector<SDL_Rect> posiciones = {
            {5, 105, 35, 90},
            {40, 105, 45, 90},
            {90, 105, 42, 90},
            {130, 105, 42, 90},
            {172, 105, 42, 90},

    };

    vector<float> duraciones = {1, 1, 1, 1, 1};
    return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente* FabricaDeAnimacionesDeGuy::saltando() {
    vector<SDL_Rect> posiciones = {
            {5, 205, 50, 90},
            {55, 195, 50, 100},
            {55, 195, 50, 100},
            {5, 205, 50, 90},
    };

    vector<float> duraciones = {1, 1, 1, 1};
    return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente* FabricaDeAnimacionesDeGuy::reposando() {
    vector<SDL_Rect> posiciones = {{5, 0, 55, 95}};
    vector<float> duraciones = {1};
    return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente *FabricaDeAnimacionesDeGuy::agachado() {
    vector<SDL_Rect> posiciones = {{343, 670, 50, 90}};
    vector<float> duraciones = {1};
    return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente* FabricaDeAnimacionesDeGuy::golpear() {
    vector<SDL_Rect> posiciones = {
            //{6, 380, 51, 100},
            {60, 380, 65, 100},
            {122, 380, 63, 100},
            {185, 380, 70, 100},
    };

    vector<float> duraciones = {1, 2, 1};
    return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 16, 4.5);
}

AnimacionCliente *FabricaDeAnimacionesDeGuy::saltandoAdelante() {
    vector<SDL_Rect> posiciones = {
            {5, 195, 50, 90},
            {55, 195, 50, 100},
            {105, 192, 60, 95},
            {165, 192, 48, 90},
            {210, 192, 65, 90},
            {280, 192, 65, 90},

    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1, 1};
    return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente *FabricaDeAnimacionesDeGuy::patadaBasica() {
    vector<SDL_Rect> posiciones = {
            //{155, 500, 45, 80},
            {200, 500, 85, 80},
    };

    vector<float> duraciones = {1, 1, 3, 2};
    return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 35, 4.5);
}