//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_FISICADEPERSONAJE_H
#define FINAL_FIGHT_FISICADEPERSONAJE_H


#include "Fisica.h"

class FisicaDePersonaje : public Fisica {

public:
    void actualizar(Mapa& mapa, Mapeable& mapeable) override;
};


#endif //FINAL_FIGHT_FISICADEPERSONAJE_H
