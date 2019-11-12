//
// Created by sebas on 30/8/19.
//

#include <algorithm>
#include "Mapa.h"
#include "../servicios/Locator.h"

using namespace std;

IdEntidad Mapa::ultimoId = 0;

Entidad *Mapa::crearEntidad() {
    auto *e = new Entidad();
    entidades[++ultimoId] = e;
    return e;
}

Entidad *Mapa::crearEntidadConId(IdEntidad idEntidad) {
    auto *e = new Entidad();
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
    colisionables.clear();
    personajes.clear();
    enemigos.clear();
    elementos.clear();
    armas.clear();
    Locator::logger()->log(DEBUG, "Se vació el vector de entidades.");
    for (auto tupla : jugadores.getJugadores()) {
        entidades[tupla.first] = tupla.second;
        personajes.insert(personajes.begin(), tupla.second);
        colisionables.insert(colisionables.begin(), tupla.second);
        Locator::logger()->log(DEBUG, "Se agregó al jugador con id de entidad " + to_string(tupla.first) +
                                      " a las entidades." );
    }
}

Entidad *Mapa::crearJugador() {
    Entidad *jugador = crearEntidad();
    jugadores.agregarJugador(ultimoId, jugador);
    return jugador;
}

void Mapa::agregarJugadorConId(IdEntidad idEntidad, Entidad *jugador) {
    jugadores.agregarJugador(idEntidad, jugador);
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

Jugadores *Mapa::getJugadores() {
    return  &jugadores;
}


void Mapa::guardarSerializado(stringstream &s) {
    lock_guard<mutex> lock(m);
    serializadoMasReciente = move(s);
}

void Mapa::serializar(ostream &stream) {
    lock_guard<mutex> lock(m);
    stream << serializadoMasReciente.str();
}

void Mapa::guardarJugador(Entidad * jugador) {
    personajes.insert(personajes.begin(), jugador);
    colisionables.insert(colisionables.begin(), jugador);
}

void Mapa::guardarEnemigo(Entidad * enemigo) {
    enemigos.insert(enemigos.begin(), enemigo);
    colisionables.insert(colisionables.begin(), enemigo);
}

void Mapa::guardarElemento(Entidad * elemento) {
    elementos.insert(elementos.begin(), elemento);
    colisionables.insert(colisionables.begin(), elemento);
}

void Mapa::guardarArma(Entidad * arma) {
    armas.insert(armas.begin(), arma);
}

vector<Entidad *> Mapa::getPersonajes() {
    return this->personajes;
}

vector<Entidad *> Mapa::getEnemigos() {
    return this->enemigos;
}

vector<Entidad *> Mapa::getElementos() {
    return this->elementos;
}

vector<Entidad *> Mapa::getArmas() {
    return this->armas;
}

vector<Entidad *> Mapa::getColisionables() {
    return this->colisionables;
}

