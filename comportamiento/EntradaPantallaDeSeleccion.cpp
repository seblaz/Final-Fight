//
// Created by sebas on 3/10/19.
//

#include <SDL_quit.h>
#include <SDL_system.h>
#include "EntradaPantallaDeSeleccion.h"
#include "../modelo/Mapa.h"
#include "../tipos/tipos.h"
#include "../niveles/Nivel.h"

void EntradaPantallaDeSeleccion::actualizar(Entidad *entidad) {
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);
    delay--;

    if ( delay < 0 && entrada[SDL_SCANCODE_RETURN]) { // Tecla enter -> avanza
        auto *mapa = entidad->getEstado<Mapa>("mapa");
        mapa->vaciarMapa();
        Entidad *jugador = Nivel::generarJugador(mapa, CODY);
        Nivel::generarNivel("nivel1", mapa, jugador);
    }
}
