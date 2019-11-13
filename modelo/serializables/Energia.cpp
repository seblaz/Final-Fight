//
// Created by franco on 29/10/19.
//

#include "Energia.h"
#include "../../servicios/Locator.h"

Energia::Energia(int puntosDeEnergia, int vidas) {
    this -> puntosDeEnergia = puntosDeEnergia;
    this -> vidas = vidas;
    this -> vivo = true;
    this -> modoTest = false;
}

void Energia::serializar(ostream &stream) {
    Serializable::serializarEntero(stream, this->puntosDeEnergia);
    Serializable::serializarEntero(stream, this->vidas);
    Serializable::serializarBoolean(stream, this->vivo);
    Serializable::serializarBoolean(stream, this->modoTest);
}

void Energia::deserializar(istream &stream) {
    this -> puntosDeEnergia = Serializable::deserializarEntero(stream);
    this -> vidas = Serializable::deserializarEntero(stream);
    this -> vivo = Serializable::deserializarBoolean(stream);
    this -> modoTest = Serializable::deserializarBoolean(stream);
}

void Energia::restarEnergia(int energiaRestada) {
    Locator::logger()->log(INFO, "Se resta puntos de vida: " + energiaRestada);

    if ( puntosDeEnergia - energiaRestada > 0 ){
        this -> puntosDeEnergia -= energiaRestada;
    }else if(!modoTest){
        if ( vidas > 1 ){
            this -> vidas -= 1;
            this -> puntosDeEnergia = 100;
        }else{
            this -> vidas = 0;
            this -> puntosDeEnergia = 0;
            this -> vivo = false;
        }
    }
}

bool Energia::personajeVive() {
    return this->vivo;
}

int Energia::getEnergia() {
    return this->puntosDeEnergia;
}

int Energia::getVidas() {
    return this->vidas;
}

void Energia::cambiarModoTest() {
    this->modoTest = !this->modoTest;
}