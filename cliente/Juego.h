//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_JUEGO_H
#define FINAL_FIGHT_JUEGO_H

#include "../modelo/Mapa.h"
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "EntradaUsuario.h"
#include "../usuario/Usuario.h"

class Juego {

private:

    void inicializarGraficos();

    SDL_Event *processInput();
    void graficar();

    SDL_Renderer *renderer_ = nullptr;
    SDL_Window *window = nullptr;
    TTF_Font *fuente = nullptr;
    bool exit = false;
    Mapa mapa_;

public:
    Juego();

    void loop();
    SDL_Renderer* renderer();
    void terminar();
};

#endif //FINAL_FIGHT_JUEGO_H