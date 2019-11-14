//
// Created by franco on 13/11/19.
//

#ifndef FINAL_FIGHT_ANIMADORARMAS_H
#define FINAL_FIGHT_ANIMADORARMAS_H


#include "Animador.h"

class AnimadorArmas : public Animador {

public:
    explicit AnimadorArmas(Entidad *entidad);

    void actualizar() override ;
};


#endif //FINAL_FIGHT_ANIMADORARMAS_H
