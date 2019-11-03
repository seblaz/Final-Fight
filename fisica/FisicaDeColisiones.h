//
// Created by franco on 31/10/19.
//

#ifndef FINAL_FIGHT_FISICADECOLISIONES_H
#define FINAL_FIGHT_FISICADECOLISIONES_H


#include "../modelo/Entidad.h"
#include "../modelo/Colisionables.h"

class FisicaDeColisiones : public Comportamiento {

    void actualizar(Entidad *) override;
};


#endif //FINAL_FIGHT_FISICADECOLISIONES_H
