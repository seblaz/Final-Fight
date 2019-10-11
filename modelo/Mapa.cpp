//
// Created by sebas on 30/8/19.
//

#include <algorithm>
#include "Mapa.h"
#include "../servicios/Locator.h"

using namespace std;

IdEntidad Mapa::ultimoId = 0;

Entidad *Mapa::crearEntidad() {
    auto* e = new Entidad();
    entidades[ultimoId++] = e;
    return e;
}

Entidad *Mapa::crearEntidadConId(IdEntidad idEntidad) {
    auto* e = new Entidad();
    entidades[idEntidad] = e;
    return e;
}

vector<Entidad *> Mapa::devolverEntidades() {
    vector<Entidad *> values(entidades.size());
    auto value_selector = [](auto pair) { return pair.second; };
    transform(entidades.begin(), entidades.end(), values.begin(), value_selector);
    return values;
}

void Mapa::vaciarMapa() {
    entidades.clear();
    Locator::logger()->log(DEBUG, "Se vació el vector de entidades.");
    for(auto tupla : jugadores){
        entidades[tupla.first] = tupla.second;
        Locator::logger()->log(DEBUG, "Se agregó al jugador con id de entidad " + to_string(tupla.first) + " a las entidades.");
    }
}

Entidad *Mapa::crearJugador() {
    Entidad *jugador = crearEntidad();
    jugadores[ultimoId] = jugador;
    return jugador;
}

void Mapa::agregarJugadorConId(IdEntidad idEntidad, Entidad *jugador) {
    jugadores[idEntidad] = jugador;
//    entidades[idEntidad] = jugador;
}

Entidad *Mapa::getJugador() {
    for(auto tuple : jugadores)
        return tuple.second;
    return nullptr;
}

Entidad *Mapa::getEntidad(IdEntidad idEntidad) {
    return entidades[idEntidad];
}

bool Mapa::contiene(IdEntidad idEntidad) {
    return !(entidades.find(idEntidad) == entidades.end());
}

unordered_map<IdEntidad, Entidad *> Mapa::devolverEntidadesConId() {
    return entidades;
}

void Mapa::quitarEntidad(IdEntidad idEntidad) {
    Locator::logger()->log(DEBUG, "Se quita la entidad: " + to_string(idEntidad));
    entidades.erase(idEntidad);
}

