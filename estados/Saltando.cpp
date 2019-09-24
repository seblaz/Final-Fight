//
// Created by franco on 8/9/19.
//

#include "Saltando.h"
#include "../servicios/Locator.h"
#include "../modelo/Velocidad.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"
#include "Caminando.h"

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
        reposar(entidad);
    }
}

void Saltando::enter(Entidad *entidad) {
    auto* animacion = FabricaDeAnimacionesDeCody::saltando();
    entidad->agregarEstado("animacion", animacion);
}

void Saltando::agachar(Entidad * entidad) {
    if ( Saltando::termine ) {
        EstadoDePersonaje::agachar(entidad);
    }else{ actualizar(entidad); }
}

void Saltando::reposar(Entidad * entidad) {
    if ( Saltando::termine ){
        EstadoDePersonaje::reposar(entidad);
    }else{ actualizar(entidad); }
}

void Saltando::saltar(Entidad *entidad) {
    if ( ! Saltando::termine ) {
        actualizar(entidad);
    }
}

void Saltando::caminar(Entidad * entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    if ( Saltando::termine ){
        EstadoDePersonaje::caminar(entidad, X_pos, X_neg, Y_pos, Y_neg);
    }else{ actualizar(entidad); }
}




