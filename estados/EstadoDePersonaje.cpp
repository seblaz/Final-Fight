//
// Created by sebas on 21/9/19.
//

#include "EstadoDePersonaje.h"
#include "Saltando.h"
#include "Caminando.h"
#include "Agachado.h"
#include "Golpeando.h"

#define RAPIDEZ 4

void EstadoDePersonaje::saltar(Entidad * entidad) {
    EstadoDePersonaje* saltando = new Saltando();
    entidad->agregarEstado("estado", saltando);
    entidad->agregarComportamiento("estado", saltando);
    //    saltando->enter(entidad);
}

void EstadoDePersonaje::reposar(Entidad * entidad) {
    EstadoDePersonaje* parado = new Reposando();
    entidad->agregarEstado("estado", parado);
    entidad->agregarComportamiento("estado", parado);
//    parado->enter(entidad);
}

void EstadoDePersonaje::agachar(Entidad * entidad) {
    EstadoDePersonaje* agachado = new Agachado();
    entidad->agregarEstado("estado", agachado);
    entidad->agregarComportamiento("estado", agachado);
//    agachado->enter(entidad);
}

void EstadoDePersonaje::caminar(Entidad * entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    EstadoDePersonaje* caminando = new Caminando();
    entidad->agregarEstado("estado", caminando);
    entidad->agregarComportamiento("estado", caminando);
//    caminando->enter(entidad);
}

void EstadoDePersonaje::golpear(Entidad * entidad) {
    EstadoDePersonaje* golpeando = new Golpeando();
    entidad->agregarEstado("estado", golpeando);
    entidad->agregarComportamiento("estado", golpeando);
//    golpeando->enter(entidad);
}

void EstadoDePersonaje::serializar(ostream &stream) {
    serializarEntero(stream, this->estadoDePersonaje);
}

void EstadoDePersonaje::deserializar(istream &stream) {
    this->nuevoEstado = static_cast<enum ESTADO>(deserializarEntero(stream));
}

EstadoDePersonaje::EstadoDePersonaje() {
    this->estadoDePersonaje = REPOSANDO;
    this->nuevoEstado = REPOSANDO;
}

enum ESTADO EstadoDePersonaje::getNuevoEstado() {
    return nuevoEstado;
}

void EstadoDePersonaje::actualizar(Entidad *entidad) {
}

bool EstadoDePersonaje::cambioElEstado() {
    return estadoDePersonaje != nuevoEstado;
}

void EstadoDePersonaje::consolidarEstados() {
    estadoDePersonaje = nuevoEstado;
}

enum ESTADO EstadoDePersonaje::getEstadoDePersonaje() {
    return estadoDePersonaje;
}
