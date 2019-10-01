//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_JUEGO_H
#define FINAL_FIGHT_JUEGO_H

#include "../modelo/Mapa.h"
#include <SDL2/SDL.h>
#include "../tipos/tipos.h"

class Juego {

private:

    void inicializarGraficos();
    void inicializarElementos();
    void terminar();

    void processInput();
    void actualizar();
    void graficar();
    void clearScene();

    SDL_Renderer *renderer_ = nullptr;
    SDL_Window *window = nullptr;
    bool exit = false;
    Mapa mapa_;

public:
    Juego();
    ~Juego() { terminar(); }

    void loop();
    Mapa &mapa();
    nombreJugador menuPrincipal();
    SDL_Renderer* renderer();

};


#endif //FINAL_FIGHT_JUEGO_H