//
// Created by sebas on 21/9/19.
//

#include "EstadoDePersonajeServidor.h"
#include "../cliente/Animador.h"
#include "../modelo/Velocidad.h"
#include "../servicios/Locator.h"
#include "Saltando.h"
#include "Caminando.h"
#include "Agachado.h"
#include "Golpeando.h"
#include "../servidor/FabricaDeAnimacionesServidor.h"
#include "../modelo/serializables/EstadoDePersonaje.h"

#define RAPIDEZ 4

void EstadoDePersonajeServidor::saltar(Entidad * entidad) {
    EstadoDePersonaje *estadoDePersonaje;
    enum PERSONAJE personaje;
    AnimacionServidor *animacion;
    if(entidad->getEstado<Velocidad>("velocidad")->x == 0){
        estadoDePersonaje = new EstadoDePersonaje(SALTANDO);

        personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
        animacion = FabricaDeAnimacionesServidor::getAnimacion(personaje, "saltando");
    } else {
        estadoDePersonaje = new EstadoDePersonaje(SALTANDO_CON_MOVIMIENTO);

        personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
        animacion = FabricaDeAnimacionesServidor::getAnimacion(personaje, "saltandoAdelante");
    }
    entidad->agregarEstado("estado de personaje", estadoDePersonaje);
    entidad->agregarComportamiento("animacion servidor", animacion);

    EstadoDePersonajeServidor* saltando = new Saltando();
    entidad->agregarComportamiento("estado", saltando);
}

void EstadoDePersonajeServidor::reposar(Entidad * entidad) {
    auto *estadoDePersonaje = new EstadoDePersonaje(REPOSANDO);
    entidad->agregarEstado("estado de personaje", estadoDePersonaje);

    EstadoDePersonajeServidor* reposando = new Reposando();
    entidad->agregarComportamiento("estado", reposando);

    enum PERSONAJE personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
    auto* animacion = FabricaDeAnimacionesServidor::getAnimacion(personaje, "reposando");
    entidad->agregarComportamiento("animacion servidor", animacion);
}

void EstadoDePersonajeServidor::agachar(Entidad * entidad) {
    auto *estadoDePersonaje = new EstadoDePersonaje(AGACHADO);
    entidad->agregarEstado("estado de personaje", estadoDePersonaje);

    EstadoDePersonajeServidor* agachado = new Agachado();
    entidad->agregarComportamiento("estado", agachado);

    enum PERSONAJE personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
    auto* animacion = FabricaDeAnimacionesServidor::getAnimacion(personaje, "agachado");
    entidad->agregarComportamiento("animacion servidor", animacion);
}

void EstadoDePersonajeServidor::caminar(Entidad * entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    auto *estadoDePersonaje = new EstadoDePersonaje(CAMINANDO);
    entidad->agregarEstado("estado de personaje", estadoDePersonaje);

    EstadoDePersonajeServidor* caminando = new Caminando();
    entidad->agregarComportamiento("estado", caminando);

    enum PERSONAJE personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
    auto* animacion = FabricaDeAnimacionesServidor::getAnimacion(personaje, "caminando");
    entidad->agregarComportamiento("animacion servidor", animacion);
}

void EstadoDePersonajeServidor::golpear(Entidad * entidad) {
    auto *estadoDePersonaje = new EstadoDePersonaje(GOLPEANDO);
    entidad->agregarEstado("estado de personaje", estadoDePersonaje);

    EstadoDePersonajeServidor* golpeando = new Golpeando();
    entidad->agregarComportamiento("estado", golpeando);

    enum PERSONAJE personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
    auto* animacion = FabricaDeAnimacionesServidor::getAnimacion(personaje, "golpeando");
    entidad->agregarComportamiento("animacion servidor", animacion);
}

void EstadoDePersonajeServidor::actualizar(Entidad *) {}
