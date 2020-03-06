//
// Created by sebas on 16/11/19.
//

#ifndef FINAL_FIGHT_ROTO_H
#define FINAL_FIGHT_ROTO_H


#include "EstadoDeElemento.h"

class Roto : public EstadoDeElemento {

public:
    using EstadoDeElemento::EstadoDeElemento;
    void recibirGolpeDe(Entidad *jugador) override {};

};


#endif //FINAL_FIGHT_ROTO_H
