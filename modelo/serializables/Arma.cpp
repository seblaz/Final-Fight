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
        case ARMA::PATADA:
            return "patada";
    };
}

Arma::Arma() : Arma(ARMA::PUNIOS){}

Arma::Arma(ARMA arma) {
    inicializar(arma);
}

void Arma::inicializar(ARMA arma_) {
    arma = arma_;
    string base = "/armas/" + Arma::armaACadena(arma);
    danio = Locator::configuracion()->getIntValue(base + "/danio");
    usosRestantes = Locator::configuracion()->getIntValue(base + "/usos");
    Locator::configuracion()->getIntValue(base + "/puntos");
}

int Arma::getPuntosDeDanio() {
    return danio;
}

void Arma::serializar(ostream &stream) {
    serializarEntero(stream, int(arma));
    serializarBoolean(stream, enSuelo);
}

void Arma::deserializar(istream &stream) {
    arma = static_cast<ARMA>(deserializarEntero(stream));
    enSuelo = deserializarBoolean(stream);
}

void Arma::usar() {
    if(--usosRestantes == 0) inicializar(ARMA::PUNIOS);
}

void Arma::tomar() {
    enSuelo = false;
}

ARMA Arma::getArma() {
    return arma;
}

bool Arma::enElSuelo() {
    return enSuelo;
}
