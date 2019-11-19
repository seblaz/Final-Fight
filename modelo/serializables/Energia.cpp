//
// Created by franco on 29/10/19.
//

#include "Energia.h"
#include "../../servicios/Locator.h"

Energia::Energia(int puntosDeEnergia, int vidas) :
        vidas(vidas),
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
        puntosDeEnergia = 0;
    }
}

bool Energia::vivo() {
    return puntosDeEnergia > 0 || vidas >= 0;
}

bool Energia::conEnergia() {
    return puntosDeEnergia > 0;
}

int Energia::getEnergia() {
    return puntosDeEnergia;
}

int Energia::getVidas() {
    return vidas;
}

void Energia::cambiarModoTest() {
    modoTest = !modoTest;
}

bool Energia::revivir() {
    if (vidas-- > 0) {
        puntosDeEnergia = puntosDeEnergiaMaximos;
        Locator::logger()->log(DEBUG, "Quedan vida/s: " + to_string(vidas));
        Locator::logger()->log(DEBUG, "Quedan puntosDeEnergia: " + to_string(puntosDeEnergia));
        return true;
    }
    return false;
}
