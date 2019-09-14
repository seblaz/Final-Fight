//
// Created by franco on 13/9/19.
//

#include "Caminando.h"
#include "Saltando.h"
#include "Agachado.h"
#include "Parado.h"

EstadoDePersonaje *Caminando::manejarEntrada(Personaje &personaje, const Uint8 *entrada){

    if (entrada[SDL_SCANCODE_S]) { // Tecla S -> El personaje Salta
        Saltando* saltando = new Saltando();
        saltando->manejarEntrada(personaje, entrada);
        return saltando;
    }else if (entrada[SDL_SCANCODE_D]){
        Agachado* agachado = new Agachado();
        agachado -> manejarEntrada(personaje, entrada);
        return agachado;
    }else if (entrada[SDL_SCANCODE_RIGHT] || entrada[SDL_SCANCODE_LEFT] || entrada[SDL_SCANCODE_DOWN] || entrada[SDL_SCANCODE_UP]){
        return nullptr;
    }else {
        return new Parado();
    }
}

Caminando::Caminando() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se instancio un objeto de clase Caminando");
}

Caminando::~Caminando() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se elimino un objeto de clase Caminando");
}

