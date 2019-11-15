//
// Created by leo on 12/11/19.
//

#include "Arma.h"
#include "../../servicios/Locator.h"

string Arma::armaACadena(ARMA arma) {
    switch (arma){
        case ARMA::PUNIOS:
            return "punios";
        case ARMA::CUCHILLO:
            return "cuchillo";
        case ARMA::TUBO:
            return "tubo";
    };
}

Arma::Arma() : Arma(ARMA::PUNIOS){}

Arma::Arma(ARMA arma) : arma(arma) {
    string base = "/armas/" + Arma::armaACadena(arma);
    danio = Locator::configuracion()->getIntValue(base + "/danio");
    usosRestantes = Locator::configuracion()->getIntValue(base + "/usos");
    puntosParaPersonaje = Locator::configuracion()->getIntValue(base + "/puntos");
}

int Arma::getPuntosDeDanio() {
    return danio;
}

int Arma::getPuntosParaPersonaje() {
    return puntosParaPersonaje;
}

void Arma::serializar(ostream &stream) {
    Serializable::serializarEntero(stream, int(arma));
}

void Arma::deserializar(istream &stream) {
    arma = static_cast<ARMA>(Serializable::deserializarEntero(stream));
}

void Arma::usar() {
    usosRestantes--;
}