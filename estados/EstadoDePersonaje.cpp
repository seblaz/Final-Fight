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
    EstadoDePersonaje* parado = new Parado();
    entidad->agregarEstado("estado", parado);
    parado->enter(entidad);

    auto* velocidad = entidad->getEstado<Velocidad>("velocidad");

    velocidad->x = 0;
    velocidad->y = 0;
}

void EstadoDePersonaje::agachar(Entidad * entidad) {
    EstadoDePersonaje* agachado = new Agachado();
    entidad->agregarEstado("estado", agachado);
    agachado->enter(entidad);

    auto* velocidad = entidad->getEstado<Velocidad>("velocidad");

    velocidad->x = 0;
    velocidad->y = 0;
}

void EstadoDePersonaje::caminar(Entidad * entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    EstadoDePersonaje* caminando = new Caminando();
    entidad->agregarEstado("estado", caminando);
    caminando->enter(entidad);

    float velocidadRelativa = Locator::configuracion()->getFloatValue("/velocidad/juego", 0);
    auto* velocidad = entidad->getEstado<Velocidad>("velocidad");

    velocidad->x = RAPIDEZ * velocidadRelativa * X_pos - RAPIDEZ * velocidadRelativa * X_neg ;
    velocidad->y = RAPIDEZ * velocidadRelativa * Y_pos - RAPIDEZ * velocidadRelativa * Y_neg ;

}
