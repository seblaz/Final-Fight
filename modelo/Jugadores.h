//
// Created by franco on 17/10/19.
//

#ifndef FINAL_FIGHT_JUGADORES_H
#define FINAL_FIGHT_JUGADORES_H

#include "Entidad.h"

class Jugadores : public Entidad {

private:
    unordered_map<IdEntidad, Entidad*> jugadores;

public:
    explicit Jugadores(unordered_map<IdEntidad, Entidad*> jugadores);

    int getMayorX();
    int getMenorX();

    void reiniciarPosiciones(int x, int y);
};


#endif //FINAL_FIGHT_JUGADORES_H
