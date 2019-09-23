//
// Created by felipe on 22/9/19.
//

#ifndef FINAL_FIGHT_NIVEL_H
#define FINAL_FIGHT_NIVEL_H


#include <SDL_system.h>
#include "../modelo/Mapa.h"
#include "../modelo/Posicion.h"
#include "../graficos/Sprite.h"

class Nivel{

public:
    static void generarNivel(const string &nivel, Mapa *mapa, Entidad *jugador);
    static Entidad *generarJugador(Mapa *mapa);
    static Entidad *generarEscenario(const string &nivel, SDL_Renderer *sdlRenderer, Mapa *mapa);
    static void generarCajas(const string &nivel, SDL_Renderer *sdlRenderer, Mapa *mapa, Posicion *posicionDeEscenario);
    static void
    generarCuchillos(const string &nivel, SDL_Renderer *sdlRenderer, Mapa *mapa, Posicion *posicionDeEscenario);
    static void generarEnemigo(const string &nivel, SDL_Renderer *sdlRenderer, Mapa *mapa, Posicion *posicionDeEscenario);
};
#endif //FINAL_FIGHT_NIVEL_H

