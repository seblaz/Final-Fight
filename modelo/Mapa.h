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
    vector<Entidad*> entidades;
    Entidad *jugador;

public:
    Entidad *crearEntidad();
    Entidad *crearJugador();
    auto devolverEntidades() -> decltype(make_iterable(entidades.begin(), entidades.end()));
    void vaciarMapa();
    Entidad *getJugador();
    Entidad *getEntidad(IdEntidad idEntidad);

};

#endif //FINAL_FIGHT_MAPA_H
