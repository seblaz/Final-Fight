//
// Created by sebas on 30/8/19.
//

#include "Mapa.h"

using namespace std;

Entidad *Mapa::crearEntidad() {
    auto* e = new Entidad();
    entidades.push_back(e);
    return e;
}

auto Mapa::devolverEntidades() -> decltype(make_iterable(entidades.begin(), entidades.end())) {
    return make_iterable(entidades.begin(), entidades.end());
}

void Mapa::vaciarMapa() {
    entidades.clear();
    Locator::logger()->log(DEBUG, "Se vacio el vector de entidades");
}

