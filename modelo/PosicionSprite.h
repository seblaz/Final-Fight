//
// Created by franco on 20/10/19.
//

#ifndef FINAL_FIGHT_POSICIONSPRITE_H
#define FINAL_FIGHT_POSICIONSPRITE_H

#include "Entidad.h"

class PosicionSprite : public Estado{

private:
    int posicion;

public:
    PosicionSprite() = default;
    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;

    void setPosicion(int pos);
    int getPosicion();
};

void PosicionSprite::serializar(ostream &stream) {
    Serializable::serializarEntero(stream, posicion);
}

void PosicionSprite::deserializar(istream &stream) {
    this->posicion = Serializable::deserializarEntero(stream);
}

void PosicionSprite::setPosicion(int posicion) {
    this->posicion = posicion;
}

int PosicionSprite::getPosicion() {
    return this->posicion;
}

#endif //FINAL_FIGHT_POSICIONSPRITE_H
