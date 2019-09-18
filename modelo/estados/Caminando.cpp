//
// Created by franco on 13/9/19.
//

#include "Caminando.h"

EstadoDePersonaje *Caminando::manejarEntrada(FisicaDePersonaje *fisica, const Uint8 *entrada){

    if (entrada[SDL_SCANCODE_S]) { // Tecla S -> El personaje Salta
        auto* saltando = new Saltando();
        saltando->manejarEntrada(fisica, entrada);
        return saltando;
    }else if (entrada[SDL_SCANCODE_D]){
        auto* agachado = new Agachado();
        agachado -> manejarEntrada(fisica, entrada);
        return agachado;
    }else if (entrada[SDL_SCANCODE_A]){
        auto* golpeando = new Golpeando();
        golpeando -> manejarEntrada(fisica, entrada);
        return golpeando;
    }else if (entrada[SDL_SCANCODE_RIGHT] || entrada[SDL_SCANCODE_LEFT] || entrada[SDL_SCANCODE_DOWN] || entrada[SDL_SCANCODE_UP]){
        return nullptr;
    }else {
        return new Parado();
    }
}

Caminando::Caminando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Caminando");
}

Caminando::~Caminando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Caminando");
}

Animacion * Caminando::devolverAnimacion() {
        return FabricaDeAnimacionesDeCody::caminado();
}

