//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_JUEGO_H
#define FINAL_FIGHT_JUEGO_H

#include "../modelo/Mapa.h"
#include <SDL2/SDL.h>
#include <SDL_ttf.h>
#include "entradas/EntradaUsuario.h"
#include "../usuario/Usuario.h"
#include "pantallas/ManagerPantallas.h"

class Juego {

private:

    void inicializarGraficos();

    SDL_Event *processInput();

    void actualizarGraficos();

    SDL_Renderer *renderer_ = nullptr;
    SDL_Window *window = nullptr;
    TTF_Font *fuente = nullptr;
    bool exit = false;
    Mapa mapa_;
    ManagerPantallas manager;

    pthread_t recibirEnHilo();
    void recibir();

public:
    Juego();

    void loop();

    SDL_Renderer *renderer();

    void terminar();
};

#endif //FINAL_FIGHT_JUEGO_H