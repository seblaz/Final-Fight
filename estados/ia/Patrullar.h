//
// Created by felipe on 22/9/19.
//

#ifndef FINAL_FIGHT_PATRULLAR_H
#define FINAL_FIGHT_PATRULLAR_H

#include "../EstadoDePersonaje.h"



class Patrullar : public EstadoDePersonaje {

private:
    int contadorDePasos = 0;
    int movimientoAnterior = 0;

public:
    Patrullar();
    ~Patrullar();
    void actualizar(Entidad *) override;
    void enter(Entidad *) override;
};


#endif //FINAL_FIGHT_PATRULLAR_H
