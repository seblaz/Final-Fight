//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_PERSONAJE_H
#define FINAL_FIGHT_PERSONAJE_H


#include "../serializar/Serializable.h"
#include "Entidad.h"

enum PERSONAJE {
    GUY,
    CODY,
    HAGGAR,
    MAKI
};

class Personaje : public Estado, Serializable {

private:
    enum PERSONAJE personaje;

public:
    Personaje();
    explicit Personaje(enum PERSONAJE personaje);
    enum PERSONAJE getPersonaje();
    void setPersonaje(enum PERSONAJE personaje);

    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;
};


#endif //FINAL_FIGHT_PERSONAJE_H
