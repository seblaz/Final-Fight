//
// Created by sebas on 10/9/19.
//

#ifndef FINAL_FIGHT_FISICADEESCENARIO_H
#define FINAL_FIGHT_FISICADEESCENARIO_H

#include "../modelo/Entidad.h"

class FisicaDeEscenario : public Comportamiento {

private:
    const int scrollDerecho = 400;
    const int scrollIzquierdo = 150;

public:
    void actualizar(Entidad *) override;
};


#endif //FINAL_FIGHT_FISICADEESCENARIO_H
