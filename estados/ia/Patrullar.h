//
// Created by felipe on 22/9/19.
//

#ifndef FINAL_FIGHT_PATRULLAR_H
#define FINAL_FIGHT_PATRULLAR_H

#include "../EstadoDePersonaje.h"
#include<stdlib.h>
#include<time.h>


class Patrullar : public Comportamiento {

private:
    int contadorDePasos = 0;
    int pasosTotales = 100;
    bool adelante = true;

public:
    Patrullar();
    ~Patrullar();
    void actualizar(Entidad *) override;
};


#endif //FINAL_FIGHT_PATRULLAR_H