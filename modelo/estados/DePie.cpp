//
// Created by franco on 6/9/19.
//
#include <SDL_system.h>
#include "DePie.h"
#include "Agachado.h"

EstadoDePersonaje* DePie::manejarEntrada(Personaje &personaje, const Uint8* entrada) {

    Velocidad &velocidad = personaje.velocidad();
    if (entrada[SDL_SCANCODE_S]) { // Tecla S -> El personaje Salta
        Saltando* saltando = new Saltando();
        saltando->manejarEntrada(personaje, entrada);
        return saltando;
    }else if (entrada[SDL_SCANCODE_D]){
        Agachado* agachado = new Agachado();
        agachado -> manejarEntrada(personaje, entrada);
        return agachado;
    }
}

void DePie::actualizar(Personaje &personaje) {
}
