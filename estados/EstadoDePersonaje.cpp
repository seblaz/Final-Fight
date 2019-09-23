//
// Created by sebas on 21/9/19.
//

#include "EstadoDePersonaje.h"
#include "Saltando.h"
#include "Caminando.h"
#include "Agachado.h"

void EstadoDePersonaje::saltar(Entidad * entidad) {
    EstadoDePersonaje* saltando = new Saltando();
    entidad->agregarComportamiento("estado", saltando);
    saltando->enter(entidad);
}

void EstadoDePersonaje::caminar(Entidad * entidad) {
    EstadoDePersonaje* caminando = new Caminando();
    entidad->agregarComportamiento("estado", caminando);
    caminando->enter(entidad);
}

void EstadoDePersonaje::reposar(Entidad * entidad) {
    EstadoDePersonaje* parado = new Parado();
    entidad->agregarComportamiento("estado", parado);
    parado->enter(entidad);
}

void EstadoDePersonaje::agachar(Entidad * entidad) {
    EstadoDePersonaje* agachado = new Agachado();
    entidad->agregarComportamiento("estado", agachado);
    agachado->enter(entidad);
}
