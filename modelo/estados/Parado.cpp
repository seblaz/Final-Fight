//
// Created by franco on 6/9/19.
//

#include "Parado.h"

EstadoDePersonaje* Parado::manejarEntrada(FisicaDePersonaje *fisica, const Uint8* entrada) {

    // TODO: Refactorizar
    if (entrada[SDL_SCANCODE_S]) { // Tecla S -> El personaje Salta
        Saltando* saltando = new Saltando();
        saltando->manejarEntrada(fisica, entrada);
        return saltando;
    }else if (entrada[SDL_SCANCODE_D]){
        Agachado* agachado = new Agachado();
        agachado -> manejarEntrada(fisica, entrada);
        return agachado;
    } else if (entrada[SDL_SCANCODE_A]) {
        Golpeando* golpeando = new Golpeando();
        golpeando->manejarEntrada(fisica, entrada);
        return golpeando;
    } else if (entrada[SDL_SCANCODE_RIGHT] || entrada[SDL_SCANCODE_LEFT] || entrada[SDL_SCANCODE_DOWN] || entrada[SDL_SCANCODE_UP]){
        Caminando* caminando = new Caminando();
        caminando -> manejarEntrada(fisica, entrada);
        return caminando;
    }else {return nullptr; }
}

Parado::Parado() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Parado");
}

Parado::~Parado() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Parado");
}

Animacion * Parado::devolverAnimacion() {
    return FabricaDeAnimacionesDeCody::parado();
}
