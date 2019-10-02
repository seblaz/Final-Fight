#include "FabricaDeAnimacionesDeHaggar.h"

Animacion* FabricaDeAnimacionesDeHaggar::caminando() {
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

Animacion* FabricaDeAnimacionesDeHaggar::reposando() {
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
            //{58, 440, 65, 90},
            {113, 440, 97, 90},
            //{203, 437, 60, 95},
            {260, 440, 60, 95},
            {320, 440, 85, 90},
    };

    vector<float> duraciones = {1, 2, 1};

    return new Animacion(posiciones, duraciones, 16, 4.5);
}

Animacion *FabricaDeAnimacionesDeHaggar::saltandoAdelante() {
    vector<SDL_Rect> posiciones = {
            {5,  212, 60, 104},
    };

    vector<float> duraciones = {1, 1, 1, 1, 1, 1, 1};

    return new Animacion(posiciones, duraciones, 60, 4.5);
}

Animacion *FabricaDeAnimacionesDeHaggar::patadaBasica() {
    vector<SDL_Rect> posiciones = {
            {195, 540, 90, 65},
    };

    vector<float> duraciones = {1, 1, 3, 2};

    return new Animacion(posiciones, duraciones, 35, 4.5);
}