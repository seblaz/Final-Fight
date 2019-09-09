//
// Created by sebas on 2/9/19.
//

#include <SDL_system.h>
#include "ComportamientoDeJugador.h"
#include "../modelo/estados/DePie.h"
#include "../modelo/estados/Saltando.h"
#include "iostream"

using namespace std;

#define RAPIDEZ 3

void ComportamientoDeJugador::actualizar(Mapeable &mapeable) {
    Personaje& personaje = (Personaje&)(mapeable);
    const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);
    Velocidad &velocidad = personaje.velocidad();

    // TODO: implementar el patron Command para eliminar los ifs.
    velocidad.x = 0;
    velocidad.y = 0;
    velocidad.z = 0;
    if (currentKeyStates[SDL_SCANCODE_RIGHT]){
        velocidad.x = RAPIDEZ;
    }
    if (currentKeyStates[SDL_SCANCODE_LEFT]){
        velocidad.x = -RAPIDEZ;
    }
    if (currentKeyStates[SDL_SCANCODE_UP]){
        velocidad.y = -RAPIDEZ;
    }
    if (currentKeyStates[SDL_SCANCODE_DOWN]){
        velocidad.y = RAPIDEZ;
    }
    EstadoDePersonaje* estado = estado_-> manejarEntrada(personaje, currentKeyStates);

    if (nullptr != estado){
        delete estado_;
        this -> estado_ = estado;
    }
}

ComportamientoDeJugador::ComportamientoDeJugador() {
    estado_ = new DePie();
}
