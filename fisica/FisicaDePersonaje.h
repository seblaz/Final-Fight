//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_FISICADEPERSONAJE_H
#define FINAL_FIGHT_FISICADEPERSONAJE_H

#include "../modelo/Posicion.h"

class FisicaDePersonaje : public Comportamiento {

public:
    void actualizar(Entidad *) override;
};


#endif //FINAL_FIGHT_FISICADEPERSONAJE_H
