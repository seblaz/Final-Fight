//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_ORIENTACION_H
#define FINAL_FIGHT_ORIENTACION_H


#include "Entidad.h"

class Orientacion : public Estado, Serializador {

public:
    bool adelante = true;

    explicit Orientacion(bool adelante = true);

    void serializar(ostream& stream);
    void deserializar(istream& stream);
};


#endif //FINAL_FIGHT_ORIENTACION_H
