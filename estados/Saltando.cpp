//
// Created by franco on 8/9/19.
//

#include "Saltando.h"
#include "../servicios/Locator.h"
#include "../modelo/Velocidad.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"
#include "Caminando.h"
#include "Agachado.h"

Saltando::Saltando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Saltando");
}

Saltando::~Saltando() {
    Logger* logger = Locator::logger();
    logger->log(DEBUG, "Se elimino un objeto de clase Saltando");
}

void Saltando::actualizar(Entidad *entidad) {
    auto* velocidad = entidad->getEstado<Velocidad>("velocidad");
    if ( subiendo_ ) {
        if (alturaMaxima_ > 1) {
            velocidad->z = -7;
            alturaMaxima_--;
        } else {
            subiendo_ = false;
            alturaMaxima_ = LIMITE;
        }
    } else if (alturaMaxima_ > 0){
        velocidad->z = 7;
        alturaMaxima_--;
    }else{
        termine = true;
        velocidad->x = 0;
        velocidad->y = 0;
        velocidad->z = 0;
        EstadoDePersonaje* parado = new Parado();
        entidad->agregarComportamiento("estado", parado);
        parado->enter(entidad);
    }
}

void Saltando::enter(Entidad *entidad) {
    auto* animacion = FabricaDeAnimacionesDeCody::saltando();
    entidad->agregarEstado("animacion", animacion);
}

void Saltando::caminar(Entidad * entidad) {
    if ( Saltando::termine ){
        EstadoDePersonaje* caminando = new Caminando();
        entidad->agregarComportamiento("estado", caminando);
        caminando->enter(entidad);
    }
}

void Saltando::agachar(Entidad * entidad) {
    if ( Saltando::termine ) {
        EstadoDePersonaje *agachado = new Agachado();
        entidad->agregarComportamiento("estado", agachado);
        agachado->enter(entidad);
    }
}

void Saltando::reposar(Entidad * entidad) {
    if ( Saltando::termine ){
        EstadoDePersonaje* parado = new Parado();
        entidad->agregarComportamiento("estado", parado);
        parado->enter(entidad);
    }
}




