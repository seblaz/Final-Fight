//
// Created by franco on 6/9/19.
//
#include <SDL_system.h>
#include "DePie.h"

EstadosDePersonaje* DePie::manejarEntrada(Personaje &personaje, const Uint8* entrada) {

    Velocidad &velocidad = personaje.velocidad();
    if (entrada[SDL_SCANCODE_S]) { // Tecla S -> El personaje Salta
        auto* saltando = new Saltando();
        saltando->manejarEntrada(personaje, entrada);

        return saltando;
    }
}

void DePie::actualizar(Personaje &personaje) {
}
