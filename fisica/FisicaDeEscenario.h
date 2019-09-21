//
// Created by sebas on 10/9/19.
//

#ifndef FINAL_FIGHT_FISICADEESCENARIO_H
#define FINAL_FIGHT_FISICADEESCENARIO_H

#include "../modelo/mapeables/Entidad.h"

class FisicaDeEscenario : public Comportamiento {

private:
    int posicion_ = 0;
    int largo_;
    const int scrollDerecho = 400;
    const int scrollIzquierdo = 150;

public:
    explicit FisicaDeEscenario(int largo);
    void actualizar(Entidad *) override;
};


#endif //FINAL_FIGHT_FISICADEESCENARIO_H
