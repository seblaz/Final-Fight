//
// Created by sebas on 30/8/19.
//

#include <algorithm>
#include "Mapa.h"
#include "../servicios/Locator.h"

using namespace std;

Entidad *Mapa::crearEntidad() {
    auto* e = new Entidad();
    entidades[e->getId()] = e;
    return e;
}

Entidad *Mapa::crearEntidadConId(IdEntidad idEntidad) {
    auto* e = new Entidad(idEntidad);
    entidades[e->getId()] = e;
    return e;
}

vector<Entidad *> Mapa::devolverEntidades() {
    vector<Entidad *> values(entidades.size());
    auto value_selector = [](auto pair){return pair.second;};
    transform(entidades.begin(), entidades.end(), values.begin(), value_selector);
    return values;
}

void Mapa::vaciarMapa() {
    entidades.clear();
    Locator::logger()->log(DEBUG, "Se vació el vector de entidades.");
    if(jugador){
        entidades[jugador->getId()] = jugador;
        Locator::logger()->log(DEBUG, "Se agregó al jugador a las entidades.");
    }
}

Entidad *Mapa::crearJugador() {
    jugador = crearEntidad();
    return jugador;
}

Entidad *Mapa::getJugador() {
    return jugador;
}

Entidad *Mapa::getEntidad(IdEntidad idEntidad) {
    return entidades[idEntidad];
}

bool Mapa::contiene(IdEntidad idEntidad) {
    return !(entidades.find(idEntidad) == entidades.end());
}