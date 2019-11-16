//
// Created by sebas on 30/8/19.
//

#include <algorithm>
#include "Mapa.h"
#include "../servicios/Locator.h"
#include "serializables/EstadoDePersonaje.h"

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

Entidad *Mapa::crearJugador() {
    Entidad *jugador = crearEntidad();
    jugadores.agregarJugador(ultimoId, jugador);
    personajes.push_back(jugador);
    colisionables.push_back(jugador);
    return jugador;
}

Entidad *Mapa::crearEnemigo() {
    auto *enemigo = crearEntidad();
    enemigos.push_back(enemigo);
    colisionables.push_back(enemigo);
    return enemigo;
}

Entidad *Mapa::crearElemento() {
    auto *elemento = crearEntidad();
    elementos.push_back(elemento);
    colisionables.push_back(elemento);
    return elemento;
}

Entidad *Mapa::crearArma() {
    auto *arma = crearEntidad();
    armas.push_back(arma);
    return arma;
}

Entidad *Mapa::crearPantalla() {
    return crearEntidad();
}

Entidad *Mapa::crearEscenario() {
    return crearEntidad();
}

Entidad *Mapa::crearTransicion() {
    return crearEntidad();
}

vector<Entidad *> &Mapa::getPersonajes() {
    return personajes;
}

vector<Entidad *> &Mapa::getEnemigos() {
    return enemigos;
}

vector<Entidad *> &Mapa::getElementos() {
    return elementos;
}

vector<Entidad *> &Mapa::getArmas() {
    return armas;
}

vector<Entidad *> &Mapa::getColisionables() {
    return colisionables;
}

bool Mapa::bloqueoEscenarioPorEnemigos() {
    for (auto* enemigo : enemigos){
        auto* estado = enemigo->getEstado<EstadoDePersonaje>("estado de personaje");
        if ( estado->getEstado() == CAMINANDO){
            return false;
        } else if ( estado->getEstado() == SALTANDO_CON_MOVIMIENTO){
            return false;
        } else if ( estado->getEstado() == SALTANDO){
            return false;
        }else if ( estado->getEstado() == RECIBIENDO_GOLPE){
            return false;
        }else if ( estado->getEstado() == DANDO_GOLPE)
            return false;
    }
    return true;
}
