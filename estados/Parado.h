//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_PARADO_H
#define FINAL_FIGHT_PARADO_H


#include "EstadoDePersonaje.h"

class Parado : public EstadoDePersonaje {

private:

public:
    Parado();
    ~Parado();
    void actualizar(Entidad *) override;
    void enter(Entidad *) override;
    void reposar(Entidad *) override  {};
};

#endif //FINAL_FIGHT_PARADO_H
