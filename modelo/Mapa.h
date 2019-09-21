//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPA_H
#define FINAL_FIGHT_MAPA_H


#include "Dimension.h"
#include "Iterator.cpp"
#include <vector>

using namespace std;

class Mapeable;

class Mapa {

private:
    vector<Mapeable*> mapeables;
    Mapeable *jugador_;

public:
    void agregar(Mapeable *mapeable);
    void agregarJugador(Mapeable *mapeable);
    auto devolverMapeables() -> decltype(make_iterable(mapeables.begin(), mapeables.end()));
    Mapeable *jugador();
    void vaciarMapa();
};

#include "mapeables/Mapeable.h"

#endif //FINAL_FIGHT_MAPA_H
