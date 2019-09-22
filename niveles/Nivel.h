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
    Nivel();
    static void generarNivel(SDL_Renderer *sdlRenderer, Mapa* mapa, int cantidadDeCajas, int cantidadDeCuchillos);

    static void crearJugador(SDL_Renderer *sdlRenderer, Mapa *mapa, Entidad *&jugador, Posicion *&posicionDeJugador);

    static void
    crearEscenario(SDL_Renderer *sdlRenderer, Mapa *mapa, Entidad *&escenario, Posicion *&posicionDeEscenario,
                   Sprite *&spriteEscenario);

    static void
    generarCajas(SDL_Renderer *sdlRenderer, Mapa *mapa, int cantidadDeCajas, Posicion *posicionDeEscenario,
                 Sprite *spriteEscenario);

    static void
    generarCuchillos(SDL_Renderer *sdlRenderer, Mapa *mapa, int cantidadCuchillos, Posicion *posicionDeEscenario,
                     Sprite *spriteEscenario);

    static void generarEnemigo(SDL_Renderer *sdlRenderer, Mapa *mapa, Posicion *posicionDeEscenario);
};
#endif //FINAL_FIGHT_NIVEL_H

