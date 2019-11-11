//
// Created by franco on 31/10/19.
//

#ifndef FINAL_FIGHT_ENVOLVENTE_H
#define FINAL_FIGHT_ENVOLVENTE_H


#include "Entidad.h"
#include "serializables/Posicion.h"

class Envolvente : public Estado{

public:
    int alto;
    int ancho;
    int profundidad;

    Posicion * posicion;
    explicit Envolvente(Posicion *posicion, int alto, int ancho, int profundidad);
    void setXposicion(Posicion* nuevaPosicion, bool orientacion);

    bool colisionaPorIzquiedaCon(Envolvente * envolvente);
    bool colisionaPorDerechaCon(Envolvente * envolvente);
    bool colisionaAbajoCon(Envolvente * envolvente);
    bool colisionaArribaCon(Envolvente * envolvente);
};


#endif //FINAL_FIGHT_ENVOLVENTE_H
