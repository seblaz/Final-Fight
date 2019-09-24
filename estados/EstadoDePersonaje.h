//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_ESTADODEPERSONAJE_H
#define FINAL_FIGHT_ESTADODEPERSONAJE_H


#include "../modelo/Entidad.h"
#include "../comportamiento/EntradaJugador.h"
#include "../modelo/Velocidad.h"
#include "../servicios/Locator.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"

class EstadoDePersonaje : public Estado {

public:
    virtual void actualizar(Entidad * entidad) {};
    virtual void enter(Entidad* entidad) = 0;
    virtual void saltar(Entidad *);
    virtual void caminar(Entidad *, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg);
    virtual void reposar(Entidad *);
    virtual void agachar(Entidad *);
    virtual void golpear(Entidad *);

};


#endif //FINAL_FIGHT_ESTADODEPERSONAJE_H
