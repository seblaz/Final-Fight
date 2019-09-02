//
// Created by sebas on 30/8/19.
//

#include "Mapa.h"
#include "Mapeable.h"

using namespace std;

Mapa::Mapa(int ancho, int largo, int altura): dimension(ancho, largo, altura){};

void Mapa::agregar(Mapeable* mapeable) {
    mapeables.push_back(mapeable);
}

auto Mapa::devolverMapeables() -> decltype(make_iterable(mapeables.begin(), mapeables.end())){
    return make_iterable(mapeables.begin(), mapeables.end());
}