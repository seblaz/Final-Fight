//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPA_H
#define FINAL_FIGHT_MAPA_H


#include "Dimension.h"
#include "Mapeable.h"
#include "Iterator.cpp"
#include <vector>

using namespace std;

class Mapa {

private:
    Dimension dimension;
    vector<Mapeable*> mapeables;

public:
    Mapa(int ancho, int largo, int altura);
    void agregar(Mapeable* mapeable);
    auto devolverMapeables() -> decltype(make_iterable(mapeables.begin(), mapeables.end()));
};


#endif //FINAL_FIGHT_MAPA_H
