//
// Created by franco on 31/10/19.
//

#ifndef FINAL_FIGHT_ENVOLVENTE_H
#define FINAL_FIGHT_ENVOLVENTE_H


#include "Entidad.h"
#include "serializables/Posicion.h"

class Envolvente : public Estado{

public:
    bool colision = false;
    int alto;
    int ancho;
    int profundidad;

    Posicion * posicion;
    explicit Envolvente(Posicion *posicion, int alto, int ancho, int profundidad);

    bool existeColisionLeft(Envolvente * envolvente);
    bool existeColisionRight(Envolvente * envolvente);
    bool existeColisionUp(Envolvente * envolvente);
    bool existeColisionDown(Envolvente * envolvente);
};


#endif //FINAL_FIGHT_ENVOLVENTE_H
