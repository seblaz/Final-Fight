//
// Created by sebas on 10/9/19.
//

#ifndef FINAL_FIGHT_FISICADEESCENARIO_H
#define FINAL_FIGHT_FISICADEESCENARIO_H

#include "../modelo/Entidad.h"

class FisicaDeEscenario : public Comportamiento {

private:
    int largo;
    int scrollDerecho;
    int scrollIzquierdo;
    int xScrollIzquierdo;
    int xScrollDerecho;
    int ancho;

public:
    explicit FisicaDeEscenario(Entidad *entidad, int largo);
    void actualizar() override;
};


#endif //FINAL_FIGHT_FISICADEESCENARIO_H
