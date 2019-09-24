//
// Created by sebas on 21/9/19.
//

#include "EstadoDePersonaje.h"
#include "Saltando.h"
#include "Caminando.h"
#include "Agachado.h"

#define RAPIDEZ 4

void EstadoDePersonaje::saltar(Entidad * entidad) {
    EstadoDePersonaje* saltando = new Saltando();
    entidad->agregarEstado("estado", saltando);
    saltando->enter(entidad);
}

void EstadoDePersonaje::reposar(Entidad * entidad) {
    EstadoDePersonaje* parado = new Reposando();
    entidad->agregarEstado("estado", parado);
    parado->enter(entidad);
}

void EstadoDePersonaje::agachar(Entidad * entidad) {
    EstadoDePersonaje* agachado = new Agachado();
    entidad->agregarEstado("estado", agachado);
    agachado->enter(entidad);
}

void EstadoDePersonaje::caminar(Entidad * entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    EstadoDePersonaje* caminando = new Caminando();
    entidad->agregarEstado("estado", caminando);
    caminando->enter(entidad);
}
