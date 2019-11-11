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
    envolventeDeAtaque->setXposicion(posicion, orientacion);

    velocidad->x = 0;
    velocidad->y = 0;

    if ( frame++ == frames_totales ) entidad->agregarComportamiento("estado", new EstadoDePersonajeServidor());
}