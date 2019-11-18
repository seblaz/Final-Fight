//
// Created by franco on 17/10/19.
//

#ifndef FINAL_FIGHT_JUGADORES_H
#define FINAL_FIGHT_JUGADORES_H

#include "Entidad.h"
#include "serializables/Posicion.h"

class Jugadores : public Estado {

private:
    unordered_map<IdEntidad, Entidad*> jugadores;

public:
    Jugadores() = default;
    explicit Jugadores(unordered_map<IdEntidad, Entidad*> jugadores);
    void agregarJugador(IdEntidad id, Entidad *jugador);
    unordered_map<IdEntidad, Entidad*>& getJugadores();

    int getMayorX();
    int getMenorX();
    bool vivos();

    void reiniciarPosiciones(int x, int y);
    void bloquearMovimientos(int scrollIzquierdo, int scrollDerecho);
    void arrastrarInactivos(int scrollIzquierdo, int scrollDerecho);

    Posicion posicionMasCercana(Posicion *posicion);
};


#endif //FINAL_FIGHT_JUGADORES_H
