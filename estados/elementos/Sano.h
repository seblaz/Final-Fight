//
// Created by sebas on 16/11/19.
//

#ifndef FINAL_FIGHT_SANO_H
#define FINAL_FIGHT_SANO_H


#include "EstadoDeElemento.h"

class Sano : public EstadoDeElemento {

public:
    using EstadoDeElemento::EstadoDeElemento;
    void recibirGolpeDe(Entidad *jugador) override;

};


#endif //FINAL_FIGHT_SANO_H
