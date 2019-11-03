//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPA_H
#define FINAL_FIGHT_MAPA_H

#include "Entidad.h"
#include "Jugadores.h"
#include "Colisionables.h"
#include <vector>
#include <mutex>

using namespace std;

/**
 * IdEntidad. Id de la entidad de tipo numérico y estático.
 */
using IdEntidad = size_t;
using IdColisionable = size_t;


class Mapa : public Estado {

private:
    static IdEntidad ultimoId;
    unordered_map<IdEntidad, Entidad*> entidades;
    unordered_map<IdEntidad, Entidad*> jugadores;

public:
    Entidad *crearEntidad();
    Entidad *crearEntidadConId(IdEntidad idEntidad);
    Entidad *crearJugador();
    void agregarJugadorConId(IdEntidad idEntidad, Entidad *jugador);
    vector<Entidad *> devolverEntidades();
    unordered_map<IdEntidad, Entidad *> devolverEntidadesConId();
    void vaciarMapa();
    void quitarEntidad(IdEntidad idEntidad);
    Entidad *getJugador();
    Jugadores* getJugadores();
    Entidad *getEntidad(IdEntidad idEntidad);
    bool contiene(IdEntidad idEntidad);
    unordered_map<IdEntidad, Entidad *> *devolverJugadores();
    Colisionables* getColisionables();
    IdEntidad getIdEntidad(Entidad *);
};

#endif //FINAL_FIGHT_MAPA_H
