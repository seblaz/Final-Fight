//
// Created by franco on 13/9/19.
//

#include <SDL_scancode.h>
#include "Caminando.h"
#include "Saltando.h"
#include "Agachado.h"
#include "Parado.h"
#include "../../servicios/Logger.h"

EstadoDePersonaje *Caminando::manejarEntrada(FisicaDePersonaje *fisica, const Uint8 *entrada){

    if (entrada[SDL_SCANCODE_S]) { // Tecla S -> El personaje Salta
        auto* saltando = new Saltando();
        saltando->manejarEntrada(fisica, entrada);
        return saltando;
    }else if (entrada[SDL_SCANCODE_D]){
        auto* agachado = new Agachado();
        agachado -> manejarEntrada(fisica, entrada);
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

