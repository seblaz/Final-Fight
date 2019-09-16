//
// Created by sebas on 10/9/19.
//

#ifndef FINAL_FIGHT_FISICADEESCENARIO_H
#define FINAL_FIGHT_FISICADEESCENARIO_H


#include "../modelo/Mapa.h"
#include "FisicaDePersonaje.h"

class FisicaDeEscenario : public Fisica {

private:
    int posicion_ = 0;
    const int scrollDerecho = 400;
    const int scrollIzquierdo = 150;
    FisicaDePersonaje &fisicaDePersonaje;

public:
    explicit FisicaDeEscenario(FisicaDePersonaje &fisicaDePersonaje);
    void actualizar() override;
    int posicion();

};


#endif //FINAL_FIGHT_FISICADEESCENARIO_H
