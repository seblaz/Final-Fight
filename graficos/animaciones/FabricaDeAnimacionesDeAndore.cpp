//
// Created by sebas on 14/9/19.
//

#include "FabricaDeAnimacionesDeAndore.h"

AnimacionCliente* FabricaDeAnimacionesDeAndore::caminando() {
    vector<SDL_Rect> posiciones = {
            //{10, 5, 55, 110},
            {62, 5, 50, 110},
            {111, 5, 50, 110},
            //{10, 5, 55, 110},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1};

    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
    return new AnimacionCliente(posiciones, 4.5);
}

AnimacionCliente* FabricaDeAnimacionesDeAndore::saltando() {
    vector<SDL_Rect> posiciones = {{10, 5, 55, 110}};

    vector<float> duraciones = {1, 1, 1, 1};

    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
    return new AnimacionCliente(posiciones, 4.5);
}

AnimacionCliente* FabricaDeAnimacionesDeAndore::reposando() {
    vector<SDL_Rect> posiciones = {{10, 5, 55, 110}};
    vector<float> duraciones = {1};

    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
    return new AnimacionCliente(posiciones, 4.5);
}

AnimacionCliente *FabricaDeAnimacionesDeAndore::agachado() {
    vector<SDL_Rect> posiciones = {{10, 5, 55, 110}};
    vector<float> duraciones = {1};

    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
    return new AnimacionCliente(posiciones, 4.5);
}

AnimacionCliente* FabricaDeAnimacionesDeAndore::golpear() {
    vector<SDL_Rect> posiciones = {
            {10, 120, 70, 110},
            {85, 120, 75, 110},
    };

    //vector<float> duraciones = {1, 1, 1, 1, 1, 1};
    return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente *FabricaDeAnimacionesDeAndore::saltandoAdelante() {
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
    return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 60, 4.5);
}

AnimacionCliente *FabricaDeAnimacionesDeAndore::patadaBasica() {
    vector<SDL_Rect> posiciones = {
            {245,  540, 60, 80},
            {315,  540, 50, 81},
            {360,  560, 85, 81},
            {315,  540, 50, 81},
    };

    vector<float> duraciones = {1, 1, 3, 2};
    return new AnimacionCliente(posiciones, 4.5);
    //return new AnimacionCliente(posiciones, duraciones, 35, 4.5);
}