//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_MODELOMENUSELECCION_H
#define FINAL_FIGHT_MODELOMENUSELECCION_H


#include "../../modelo/serializables/NombrePantalla.h"
#include "Modelo.h"

class ModeloMenuSeleccion : public Modelo {

public:
    void serializar(ostream &stream) override {};
    void deserializar(istream &stream) override {};

};


#endif //FINAL_FIGHT_MODELOMENUSELECCION_H
