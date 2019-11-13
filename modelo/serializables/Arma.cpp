//
// Created by leo on 12/11/19.
//

#include "Arma.h"
#include "../../servicios/Locator.h"

int Arma::getPuntosDeDanio() {
    return puntosDeDanio;
}

int Arma::getPuntosParaPersonaje() {
    return puntosParaPersonaje;
}

void Arma::restarUso(){
    Locator::logger()->log(DEBUG, "Se resta un uso al arma. Usos disponibles: " + usosPendientes);
    usosPendientes--;
}