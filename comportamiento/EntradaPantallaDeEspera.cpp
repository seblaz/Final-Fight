//
// Created by sebas on 3/10/19.
//

#include <SDL_quit.h>
#include <SDL_system.h>
#include "EntradaPantallaDeEspera.h"
#include "../modelo/Mapa.h"
#include "../niveles/Nivel.h"

void EntradaPantallaDeEspera::actualizar(Entidad *entidad) {
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);

    if (entrada[SDL_SCANCODE_RETURN]) { // Tecla enter -> avanza
        auto *mapa = entidad->getEstado<Mapa>("mapa");
        mapa->vaciarMapa();
        Nivel::generarMenuSeleccion(mapa);
    }
}

