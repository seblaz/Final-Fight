//
// Created by leo on 12/11/19.
//

#include "Arma.h"
#include "../../servicios/Locator.h"

void Arma::serializar(ostream &stream) {
    Serializable::serializarEntero(stream, this->usosPendientes);
    Serializable::serializarEntero(stream, this->puntosParaPersonaje);
    Serializable::serializarEntero(stream, this->puntosDeDanio);
    Serializable::serializarEntero(stream, int(this->tipoArma));
}

void Arma::deserializar(istream &stream) {
    this->usosPendientes = Serializable::deserializarEntero(stream);
    this->puntosParaPersonaje = Serializable::deserializarEntero(stream);
    this->puntosDeDanio = Serializable::deserializarEntero(stream);
    this->tipoArma = static_cast<TIPO_ARMA>(Serializable::deserializarEntero(stream));
}

int Arma::getPuntosDeDanio() {
    return puntosDeDanio;
}

int Arma::getPuntosParaPersonaje() {
    return puntosParaPersonaje;
}

void Arma::restarUso(){
    usosPendientes--;
    Locator::logger()->log(DEBUG, "Se resta un uso al arma. Usos disponibles: " + to_string(usosPendientes));
}

ArmaPunios::ArmaPunios(){
    this->usosPendientes = -1;
    this->puntosParaPersonaje = 100;
    this->puntosDeDanio = 20;
    this->tipoArma = TIPO_ARMA::ArmaPunios;
}

Cuchillo::Cuchillo(){
    this->usosPendientes = 3;
    this->puntosParaPersonaje = 150;
    this->puntosDeDanio = 50;
    this->tipoArma = TIPO_ARMA::Cuchillo;
}

Tubo::Tubo(){
    this->usosPendientes = 3;
    this->puntosParaPersonaje = 200;
    this->puntosDeDanio = 35;
    this->tipoArma = TIPO_ARMA::Tubo;
}