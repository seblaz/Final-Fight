//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_COMPORTAMIENTODEJUGADOR_H
#define FINAL_FIGHT_COMPORTAMIENTODEJUGADOR_H


#include "Comportamiento.h"
#include "../modelo/estados/EstadosDePersonaje.h"

class ComportamientoDeJugador : public Comportamiento {

private:
    EstadosDePersonaje* estado_;

public:
    ComportamientoDeJugador();
    void actualizar(Mapeable &mapeable) override;
    ~ComportamientoDeJugador() override = default;
};


#endif //FINAL_FIGHT_COMPORTAMIENTODEJUGADOR_H
