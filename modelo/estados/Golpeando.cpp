//
// Created by franco on 13/9/19.
//

#include "Golpeando.h"

EstadoDePersonaje *Golpeando::manejarEntrada(FisicaDePersonaje *fisica, const Uint8 *entrada){
    if ( entrada[SDL_SCANCODE_A] ) {
        fisica->cambiarVelocidadX(0);
        fisica->cambiarVelocidadY(0);
        fisica->cambiarVelocidadZ(0);

        return nullptr;
    }
    else if (entrada[SDL_SCANCODE_S]) { // Tecla S -> El personaje Salta
        auto* saltando = new Saltando();
        saltando->manejarEntrada(fisica, entrada);
        return saltando;
    }else if (entrada[SDL_SCANCODE_D]){
        auto* agachado = new Agachado();
        agachado -> manejarEntrada(fisica, entrada);
        return agachado;
    }else if (entrada[SDL_SCANCODE_RIGHT] || entrada[SDL_SCANCODE_LEFT] || entrada[SDL_SCANCODE_DOWN] || entrada[SDL_SCANCODE_UP]){
        Caminando* caminando = new Caminando();
        caminando -> manejarEntrada(fisica, entrada);
        return caminando;
    }else {
        return new Parado();
    }
}

Golpeando::Golpeando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Golpeando");
}

Golpeando::~Golpeando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Golpeando");
}

Animacion *Golpeando::devolverAnimacion() {
        return FabricaDeAnimacionesDeCody::golpear();
}