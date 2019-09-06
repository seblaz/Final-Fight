//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_JUEGO_H
#define FINAL_FIGHT_JUEGO_H

#include "../modelo/mapeables/Mapeable.h"
#include "../modelo/Mapa.h"
#include <SDL2/SDL.h>

class Juego {

private:

    void processInput();
    void update();
    void render();

    SDL_Renderer* renderer = nullptr;
    SDL_Window *window = nullptr;
    bool exit = false;
    Mapa mapa;

public:
    explicit Juego(Mapa &mapa) : mapa(mapa) {}
    void initialize();
    void loop();
    void finish();
};


#endif //FINAL_FIGHT_JUEGO_H
