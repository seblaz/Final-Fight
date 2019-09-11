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
    Dimension dimension;
    vector<Mapeable*> mapeables;

public:
    Mapa(int ancho, int largo, int altura);
    void agregar(Mapeable *mapeable);
    auto devolverMapeables() -> decltype(make_iterable(mapeables.begin(), mapeables.end()));

};

#include "mapeables/Mapeable.h"

#endif //FINAL_FIGHT_MAPA_H