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
    FisicaDePersonaje *fisica;
    int contadorDePasos = 0;
    int movimientoAnterior = 0;
    FabricaDeAnimacionesDePoison *fabricaDeAnimaciones;
    Animacion *animacionActual;

public:
    explicit ComportamientoDeEnemigo(FisicaDePersonaje *fisica, FabricaDeAnimacionesDePoison *fabrica);
    void actualizar() override;
    Animacion* devolverAnimacion();
    ~ComportamientoDeEnemigo();
};

#endif //FINAL_FIGHT_COMPORTAMIENTODEENEMIGO_H
