//
// Created by sebas on 30/8/19.
//

#include "Mapa.h"

using namespace std;

void Mapa::agregar(Mapeable *mapeable) {
    mapeables.push_back(mapeable);
}

void Mapa::agregarJugador(Mapeable *nuevoJugador) {
    jugador_ = nuevoJugador;
    agregar(nuevoJugador);
}

auto Mapa::devolverMapeables() -> decltype(make_iterable(mapeables.begin(), mapeables.end())) {
    return make_iterable(mapeables.begin(), mapeables.end());
}

Mapeable *Mapa::jugador() {
    return jugador_;
}

void Mapa::vaciarMapa() {
    bool resultado = mapeables.empty();
    Locator::logger()->log(DEBUG, &"Se vacio el vector de mapeables con resultado: "[resultado]);
}

