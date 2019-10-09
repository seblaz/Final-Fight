//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPA_H
#define FINAL_FIGHT_MAPA_H


#include "Iterator.cpp"
#include "Entidad.h"
#include <vector>
#include <mutex>

using namespace std;

/**
 * IdEntidad. Id de la entidad de tipo numérico y estático.
 */
using IdEntidad = size_t;

class Mapeable;

class Mapa : public Estado {

private:
    static IdEntidad ultimoId;
    unordered_map<IdEntidad, Entidad*> entidades;
    unordered_map<IdEntidad, Entidad*> jugadores;
    mutex m;

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
    Entidad *getEntidad(IdEntidad idEntidad);
    bool contiene(IdEntidad idEntidad);
};

#endif //FINAL_FIGHT_MAPA_H
