//
// Created by franco on 13/9/19.
//

#include "Caminando.h"
#include "../servicios/Locator.h"

Caminando::Caminando(){
    estadoDePersonaje = CAMINANDO;
    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se instancio un objeto de clase Caminando");
}

Caminando::~Caminando() {
    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se elimino un objeto de clase Caminando");
}


void Caminando::enter(Entidad *entidad) {
    auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
    auto *animacion = fabricaDeAnimaciones->caminando();
    entidad->agregarEstado("animacion", animacion);
}

#define RAPIDEZ 4

void Caminando::caminar(Entidad *entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    float velocidadRelativa = Locator::configuracion()->getFloatValue("/velocidad/juego", 0);
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");

    velocidad->x = RAPIDEZ * velocidadRelativa * X_pos - RAPIDEZ * velocidadRelativa * X_neg;
    velocidad->y = RAPIDEZ * velocidadRelativa * Y_pos - RAPIDEZ * velocidadRelativa * Y_neg;
}



