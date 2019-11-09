//
// Created by franco on 31/10/19.
//

#ifndef FINAL_FIGHT_COLISIONABLES_H
#define FINAL_FIGHT_COLISIONABLES_H


#include "Entidad.h"
#include "Jugadores.h"

class Colisionables {

private:
    unordered_map<IdEntidad, Entidad*> colisionables;

public:
    explicit Colisionables(unordered_map<IdEntidad, Entidad *>  colisionables);
    void add(Entidad *);

    void calcularPosiblesColisiones(Entidad *);
    void calcularPosiblesColisiones();
};


#endif //FINAL_FIGHT_COLISIONABLES_H
