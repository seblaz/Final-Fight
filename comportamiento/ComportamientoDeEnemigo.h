//
// Created by felis on 2/9/19.
//

#ifndef FINAL_FIGHT_COMPORTAMIENTODEENEMIGO_H
#define FINAL_FIGHT_COMPORTAMIENTODEENEMIGO_H


#include "Comportamiento.h"
#include "../modelo/estados/EstadoDePersonaje.h"

class ComportamientoDeEnemigo : public Comportamiento {

private:
    EstadoDePersonaje* estado_;
    int movimientoAnterior;
    int contadorDePasos;

public:
    ComportamientoDeEnemigo();
    void actualizar(Mapeable &mapeable) override;
    ~ComportamientoDeEnemigo() override;
};


#endif //FINAL_FIGHT_COMPORTAMIENTODEENEMIGO_H
