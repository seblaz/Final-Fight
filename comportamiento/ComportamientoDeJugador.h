//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_COMPORTAMIENTODEJUGADOR_H
#define FINAL_FIGHT_COMPORTAMIENTODEJUGADOR_H


#include "Comportamiento.h"
#include "../modelo/estados/EstadoDePersonaje.h"
#include "../fisica/FisicaDePersonaje.h"

class ComportamientoDeJugador : public Comportamiento {

private:
    EstadoDePersonaje* estado_;
    FisicaDePersonaje *fisica;
    FabricaDeAnimacionesDeCody *fabricaDeAnimaciones;
    Animacion *animacionActual;

public:
    explicit ComportamientoDeJugador(FisicaDePersonaje *fisica, FabricaDeAnimacionesDeCody *fabrica);
    void actualizar() override;
    Animacion* devolverAnimacion();
    ~ComportamientoDeJugador();
};


#endif //FINAL_FIGHT_COMPORTAMIENTODEJUGADOR_H
