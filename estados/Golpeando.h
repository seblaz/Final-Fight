//
// Created by franco on 24/9/19.
//

#ifndef FINAL_FIGHT_GOLPEANDO_H
#define FINAL_FIGHT_GOLPEANDO_H

#include "EstadoDePersonaje.h"

class Golpeando : public EstadoDePersonaje{

public:
    Golpeando();
    ~Golpeando();

    void actualizar(Entidad *) override;
    void enter(Entidad *entidad) override;
    void golpear(Entidad *) override {};
};
#endif //FINAL_FIGHT_GOLPEANDO_H
