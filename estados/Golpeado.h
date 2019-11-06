//
// Created by franco on 3/11/19.
//

#ifndef FINAL_FIGHT_GOLPEADO_H
#define FINAL_FIGHT_GOLPEADO_H


#include "EstadoDePersonajeServidor.h"

class Golpeado : public EstadoDePersonajeServidor{

public:
    Golpeado();
    ~Golpeado();

    void actualizar(Entidad *) override;
    void golpear(Entidad *) override {};
    void saltar(Entidad *) override {};
    void caminar(Entidad *, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) override {};
    void reposar(Entidad *) override {};
    void agachar(Entidad *) override {};
    void golpeado(Entidad *) override {};
};


#endif //FINAL_FIGHT_GOLPEADO_H
