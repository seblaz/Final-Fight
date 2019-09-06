//
// Created by sebas on 2/9/19.
//

#include <SDL_system.h>
#include "ComportamientoDeJugador.h"
#include "../modelo/mapeables/Personaje.h"

void ComportamientoDeJugador::actualizar(Mapeable &mapeable) {
    Personaje& personaje = (Personaje&)(mapeable);
    const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);
    Velocidad &velocidad = personaje.velocidad();

    // TODO: implementar el patron Command para eliminar los ifs.
    if (currentKeyStates[SDL_SCANCODE_RIGHT]){
        velocidad.x = 1;
        velocidad.y = 0;
        velocidad.z = 0;
    }else if (currentKeyStates[SDL_SCANCODE_LEFT]){
        velocidad.x = -1;
        velocidad.y = 0;
        velocidad.z = 0;
    }else if (currentKeyStates[SDL_SCANCODE_UP]){
        velocidad.x = 0;
        velocidad.y = -1;
        velocidad.z = 0;
    }else if (currentKeyStates[SDL_SCANCODE_DOWN]){
        velocidad.x = 0;
        velocidad.y = 1;
        velocidad.z = 0;
    } else {
        velocidad.x = 0;
        velocidad.y = 0;
        velocidad.z = 0;
    }
}
