//
// Created by franco on 17/10/19.
//

#ifndef FINAL_FIGHT_JUGADORES_H
#define FINAL_FIGHT_JUGADORES_H

#include "Entidad.h"
#include "Posicion.h"

class Jugadores : public Estado {

private:
    unordered_map<IdEntidad, Entidad*> jugadores;
    unordered_map<IdEntidad, Posicion*> posiciones;

public:
    explicit Jugadores(unordered_map<IdEntidad, Entidad*> jugadores);

    int getMayorX();
    int getMenorX();

    void reiniciarPosiciones(int x, int y);
    unordered_map<IdEntidad, Posicion*> *getPosiciones();

    void bloquearMovientos(int scrollIzquierdo, int scrollDerecho);
    void arrastrarInactivos(int scrollIzquierdo, int scrollDerecho);
};


#endif //FINAL_FIGHT_JUGADORES_H
