//
// Created by franco on 8/9/19.
//

#include "Agachado.h"
#include "Parado.h"

EstadoDePersonaje *Agachado::manejarEntrada(Personaje &personaje, const Uint8 *entrada) {
    if ( entrada[SDL_SCANCODE_D] ){
        return nullptr;
    }else if ( entrada[SDL_SCANCODE_S] ){
        Saltando* saltando = new Saltando();
        saltando->manejarEntrada(personaje, entrada);
        return saltando;
    }else{
        return new Parado();
    }
}

Agachado::Agachado() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se instancio un objeto de clase Agachado");
}

Agachado::~Agachado() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se elimino un objeto de clase Agachado");
}

