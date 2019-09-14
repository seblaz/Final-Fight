//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_FISICADEPERSONAJE_H
#define FINAL_FIGHT_FISICADEPERSONAJE_H


#include "Fisica.h"
#include "../modelo/Posicion.h"

class FisicaDePersonaje : public Fisica {

private:
    Posicion posicion_;
    Velocidad velocidad_;

public:
    explicit FisicaDePersonaje(int x = 0, int y = 0, int z = 0);
    void actualizar() override;
    Posicion& posicion();
    Velocidad& velocidad();
};


#endif //FINAL_FIGHT_FISICADEPERSONAJE_H
