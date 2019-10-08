//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPA_H
#define FINAL_FIGHT_MAPA_H


#include "Iterator.cpp"
#include "Entidad.h"
#include <vector>

using namespace std;

class Mapeable;

class Mapa : public Estado {

private:
    unordered_map<IdEntidad, Entidad*> entidades;
    Entidad *jugador;

public:
    Entidad *crearEntidad();
    Entidad *crearJugador();
    vector<Entidad *> devolverEntidades();
    void vaciarMapa();
    Entidad *getJugador();
    Entidad *getEntidad(IdEntidad idEntidad);

};

#endif //FINAL_FIGHT_MAPA_H
