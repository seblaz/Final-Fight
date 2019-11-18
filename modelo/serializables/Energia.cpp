//
// Created by franco on 29/10/19.
//

#include "Energia.h"
#include "../../servicios/Locator.h"

Energia::Energia(int puntosDeEnergia, int vidas) :
        vidas(vidas),
        modoTest(false),
        puntosDeEnergia(puntosDeEnergia),
        puntosDeEnergiaMaximos(puntosDeEnergia) {}

void Energia::serializar(ostream &stream) {
    serializarEntero(stream, vidas);
    serializarBoolean(stream, modoTest);
    serializarEntero(stream, puntosDeEnergia);
    serializarEntero(stream, puntosDeEnergiaMaximos);
}

void Energia::deserializar(istream &stream) {
    vidas = deserializarEntero(stream);
    modoTest = deserializarBoolean(stream);
    puntosDeEnergia = deserializarEntero(stream);
    puntosDeEnergiaMaximos = deserializarEntero(stream);
}

void Energia::restarEnergia(int energiaRestada) {
    Locator::logger()->log(DEBUG, "Se resta puntos de vida: " + to_string(energiaRestada));

    if (puntosDeEnergia - energiaRestada > 0) {
        puntosDeEnergia -= energiaRestada;
    } else if (!modoTest) {
        if (vidas-- > 1) {
            this->puntosDeEnergia = puntosDeEnergiaMaximos;
        } else {
            this->puntosDeEnergia = 0;
        }
        Locator::logger()->log(DEBUG, "Quedan vida/s: " + to_string(vidas));
        Locator::logger()->log(DEBUG, "Quedan puntosDeEnergia: " + to_string(puntosDeEnergia));
    }
}

bool Energia::personajeVive() {
    return puntosDeEnergia > 0;
}

int Energia::getEnergia() {
    return puntosDeEnergia;
}

int Energia::getVidas() {
    return vidas;
}

void Energia::cambiarModoTest() {
    this->modoTest = !this->modoTest;
}