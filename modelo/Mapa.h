//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPA_H
#define FINAL_FIGHT_MAPA_H


#include "Dimension.h"
#include "Iterator.cpp"
#include "mapeables/Entidad.h"
#include <vector>

using namespace std;

class Mapeable;

class Mapa {

private:
    vector<Entidad*> entidades;

public:
    Entidad *crearEntidad();
    auto devolverEntidades() -> decltype(make_iterable(entidades.begin(), entidades.end()));
    void vaciarMapa();

};

#endif //FINAL_FIGHT_MAPA_H
