//
// Created by sebas on 11/11/19.
//

#ifndef FINAL_FIGHT_ENVOLVENTEATAQUE_H
#define FINAL_FIGHT_ENVOLVENTEATAQUE_H


#include "../Entidad.h"
#include "Envolvente.h"
#include "../serializables/Orientacion.h"
#include "EnvolventeVolumen.h"
#include "../serializables/Arma.h"

class EnvolventeAtaque : public Envolvente {

private:
    Orientacion *orientacion;

public:
    explicit EnvolventeAtaque(Posicion *posicion, int ancho, int profundidad, Orientacion *orientacion);
    bool colisionaCon(EnvolventeVolumen *envolvente, Arma *longitudArma);

};


#endif //FINAL_FIGHT_ENVOLVENTEATAQUE_H
