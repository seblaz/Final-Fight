//
// Created by franco on 24/9/19.
//

#include "Golpeando.h"
#include "../modelo/Envolvente.h"
#include "../modelo/serializables/Orientacion.h"

Golpeando::Golpeando() {
    Logger* logger = Locator::logger();
//    logger -> log(DEBUG, "Se instancio un objeto de clase Golpeando");
}

Golpeando::~Golpeando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se elimino un objeto de clase Golpeando");
}

void Golpeando::actualizar(Entidad * entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    auto *posicion = entidad->getEstado<Posicion>("posicion");
    auto *envolventeDeAtaque = entidad->getEstado<Envolvente>("envolvente ataque");
    auto orientacion = entidad->getEstado<Orientacion>("orientacion")->adelante;
    velocidad->x = 0;
    velocidad->y = 0;
    envolventeDeAtaque->setXposicion(posicion, orientacion);
    if ( frame == frames_totales ){
        termine = true;
        //EstadoDePersonajeServidor::reposar(entidad);
    }else {
        frame++;
    }
}

void Golpeando::reposar(Entidad * entidad) {
    if ( Golpeando::termine )
        EstadoDePersonajeServidor::reposar(entidad);
}

void Golpeando::caminar(Entidad * entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    if ( Golpeando::termine )
        EstadoDePersonajeServidor::caminar(entidad, X_pos, X_neg, Y_pos, Y_neg);
}

void Golpeando::agachar(Entidad * entidad) {
    if ( Golpeando::termine )
        EstadoDePersonajeServidor::agachar(entidad);
}

void Golpeando::saltar(Entidad *entidad) {
    if ( Golpeando::termine )
        EstadoDePersonajeServidor::saltar(entidad);
}

