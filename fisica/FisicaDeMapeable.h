//
// Created by felipe on 14/9/19.
//

#include "Fisica.h"
#include "../modelo/Posicion.h"

#ifndef FINAL_FIGHT_FISICADEOBJETO_H
#define FINAL_FIGHT_FISICADEOBJETO_H

class FisicaDeMapeable : public Fisica {

private:
    Posicion posicion_;

public:
    FisicaDeMapeable(int x, int y, int z);
    void actualizar() override {};
    Posicion posicion();

};

#endif //FINAL_FIGHT_FISICADEOBJETO_H