#include "FabricaDeAnimacionesDeMaki.h"

AnimacionCliente* FabricaDeAnimacionesDeMaki::caminando() {
    vector<SDL_Rect> posiciones = {
            {0, 105, 35, 90},
            {35, 105, 45, 90},
            {80, 105, 35, 90},
            {115, 105, 28, 90},
            {140, 105, 45, 90},
    };

    //vector<float> duraciones = {1, 1, 1, 1, 1, 1};
        return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente* FabricaDeAnimacionesDeMaki::saltando() {
    vector<SDL_Rect> posiciones = {
            {318, 85, 46, 90},
            {318, 85, 46, 90},
            {272, 95, 46, 100},
    };

    //vector<float> duraciones = {1, 1, 1, 1};
        return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente* FabricaDeAnimacionesDeMaki::reposando() {
    vector<SDL_Rect> posiciones = {{0, 0, 45, 95}};
    //vector<float> duraciones = {1};
        return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente *FabricaDeAnimacionesDeMaki::agachado() {
    vector<SDL_Rect> posiciones = {{45, 6, 45, 90}};
    //vector<float> duraciones = {1};
        return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente* FabricaDeAnimacionesDeMaki::golpear() {
    vector<SDL_Rect> posiciones = {
            //{0, 200, 51, 90},
            {50, 200, 70, 90},
            {118, 200, 55, 90},
            //{168, 200, 70, 90},
            {395, 180, 43, 110},
            {395, 180, 43, 110},

    };

    //vector<float> duraciones = {1, 2, 1};
        return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 16, 4.5);
}

AnimacionCliente *FabricaDeAnimacionesDeMaki::saltandoAdelante() {
    vector<SDL_Rect> posiciones = {
            {365, 85, 50, 90},
            {418, 85, 50, 90},
            {465, 85, 55, 90},
            {522, 85, 50, 90},

    };

    //vector<float> duraciones = {1, 1, 1, 1, 1, 1, 1};
        return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente *FabricaDeAnimacionesDeMaki::patadaBasica() {
    vector<SDL_Rect> posiciones = {
            {170, 400, 80, 80},
    };

    //vector<float> duraciones = {1, 1, 3, 2};
        return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 35, 4.5);
}