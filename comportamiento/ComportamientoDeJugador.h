//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_COMPORTAMIENTODEJUGADOR_H
#define FINAL_FIGHT_COMPORTAMIENTODEJUGADOR_H


#include "Comportamiento.h"

class ComportamientoDeJugador : public Comportamiento {

public:
    void actualizar(Mapeable &mapeable) override;
    ~ComportamientoDeJugador() override = default;
};


#endif //FINAL_FIGHT_COMPORTAMIENTODEJUGADOR_H
