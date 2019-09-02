//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_GAME_H
#define FINAL_FIGHT_GAME_H

#include "../model/mapeables/Mapeable.h"
#include "../model/Mapa.h"
#include <SDL2/SDL.h>

class Game {

private:

    void initialize();
    void loop();
    void processInput();
    void update();
    void render();
    void finish();

    SDL_Surface *screenSurface = nullptr;
    SDL_Window *window = nullptr;
    bool exit = false;
    Mapa mapa;

public:
    explicit Game(Mapa &mapa) : mapa(mapa) {
        initialize();
        loop();
        finish();
    }
};


#endif //FINAL_FIGHT_GAME_H
