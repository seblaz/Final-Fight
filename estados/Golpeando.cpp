//
// Created by franco on 24/9/19.
//

#include "Golpeando.h"

Golpeando::Golpeando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Golpeando");
}

Golpeando::~Golpeando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se elimino un objeto de clase Golpeando");
}

//void Golpeando::enter(Entidad *entidad) {
//    auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
//    auto* animacion = fabricaDeAnimaciones->golpear();
//    entidad->agregarEstado("animacion", animacion);
//}

void Golpeando::actualizar(Entidad * entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->x = 0;
    velocidad->y = 0;
    if ( frame == frames_totales ){
        termine = true;
    }else {
        frame++;
    }
}

void Golpeando::reposar(Entidad * entidad) {
    if ( Golpeando::termine )
        EstadoDePersonaje::reposar(entidad);
}

void Golpeando::caminar(Entidad * entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    if ( Golpeando::termine )
        EstadoDePersonaje::caminar(entidad, X_pos, X_neg, Y_pos, Y_neg);
}

void Golpeando::agachar(Entidad * entidad) {
    if ( Golpeando::termine )
        EstadoDePersonaje::agachar(entidad);
}

void Golpeando::saltar(Entidad *entidad) {
    if ( Golpeando::termine )
        EstadoDePersonaje::saltar(entidad);
}

