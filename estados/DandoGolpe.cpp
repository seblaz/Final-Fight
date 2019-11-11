//
// Created by franco on 24/9/19.
//

#include "DandoGolpe.h"
#include "../modelo/Envolvente.h"
#include "../modelo/serializables/Orientacion.h"

DandoGolpe::DandoGolpe() {
    Logger* logger = Locator::logger();
//    logger -> log(DEBUG, "Se instancio un objeto de clase DandoGolpe");
}

DandoGolpe::~DandoGolpe() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se elimino un objeto de clase DandoGolpe");
}

void DandoGolpe::actualizar(Entidad * entidad) {
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

void DandoGolpe::reposar(Entidad * entidad) {
    if ( DandoGolpe::termine )
        EstadoDePersonajeServidor::reposar(entidad);
}

void DandoGolpe::caminar(Entidad * entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    if ( DandoGolpe::termine )
        EstadoDePersonajeServidor::caminar(entidad, X_pos, X_neg, Y_pos, Y_neg);
}

void DandoGolpe::agachar(Entidad * entidad) {
    if ( DandoGolpe::termine )
        EstadoDePersonajeServidor::agachar(entidad);
}

void DandoGolpe::saltar(Entidad *entidad) {
    if ( DandoGolpe::termine )
        EstadoDePersonajeServidor::saltar(entidad);
}

