//
// Created by franco on 23/9/19.
//

#ifndef FINAL_FIGHT_ENTRADAJUGADOR_H
#define FINAL_FIGHT_ENTRADAJUGADOR_H

#include "../modelo/Entidad.h"

//enum DIRECCION { NEGATIVO = -1, POSITIVO = 1, NEUTRO = 0 };
//enum DIRECCION { X_POS =, POSITIVO = 1, NEUTRO = 0 };

class EntradaJugador : public Comportamiento{

public:
    void actualizar(Entidad *) override ;
};

#endif //FINAL_FIGHT_ENTRADAJUGADOR_H
