//
// Created by sebas on 11/11/19.
//

#ifndef FINAL_FIGHT_ENVOLVENTEATAQUE_H
#define FINAL_FIGHT_ENVOLVENTEATAQUE_H


#include "../Entidad.h"
#include "Envolvente.h"
#include "../serializables/Orientacion.h"
#include "EnvolventeVolumen.h"

class EnvolventeAtaque : public Envolvente {

private:
    Orientacion *orientacion;

public:
    explicit EnvolventeAtaque(Posicion *posicion, int alto, int ancho, int profundidad, Orientacion *orientacion);
    bool colisionaCon(EnvolventeVolumen *envolvente);

};


#endif //FINAL_FIGHT_ENVOLVENTEATAQUE_H
