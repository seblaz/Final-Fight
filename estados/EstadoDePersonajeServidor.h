//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_ESTADODEPERSONAJESERVIDOR_H
#define FINAL_FIGHT_ESTADODEPERSONAJESERVIDOR_H


#include "../modelo/Entidad.h"
#include "../cliente/Animador.h"
#include "../modelo/Velocidad.h"
#include "../servicios/Locator.h"

class EstadoDePersonajeServidor : public Comportamiento {

public:
    virtual void saltar(Entidad *);
    virtual void caminar(Entidad *, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg);
    virtual void reposar(Entidad *);
    virtual void agachar(Entidad *);
    virtual void golpear(Entidad *);

    void actualizar(Entidad * entidad) override;
};


#endif //FINAL_FIGHT_ESTADODEPERSONAJESERVIDOR_H
