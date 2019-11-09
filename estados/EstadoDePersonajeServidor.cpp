//
// Created by sebas on 21/9/19.
//

#include "EstadoDePersonajeServidor.h"
#include "../servicios/Locator.h"
#include "Saltando.h"
#include "Caminando.h"
#include "Agachado.h"
#include "Golpeando.h"
#include "../servidor/FabricaDeAnimacionesServidor.h"
#include "../modelo/serializables/EstadoDePersonaje.h"
#include "Golpeado.h"

template<typename T>
EstadoDePersonajeServidor *crearEstado() { return new T; }

map<ESTADO_DE_PERSONAJE, EstadoDePersonajeServidor *(*)()> EstadoDePersonajeServidor::mapa = {
        {CAMINANDO, &crearEstado<Caminando>},
        {SALTANDO, &crearEstado<Saltando>},
        {SALTANDO_CON_MOVIMIENTO, &crearEstado<Saltando>},
        {REPOSANDO, &crearEstado<Reposando>},
        {GOLPEANDO, &crearEstado<Golpeando>},
        {AGACHADO, &crearEstado<Agachado>},
        {GOLPEADO, &crearEstado<Golpeado>},
};

void EstadoDePersonajeServidor::agregarEstado(Entidad *entidad, ESTADO_DE_PERSONAJE estado) {
    auto *estadoDePersonaje = new EstadoDePersonaje(estado);
    entidad->agregarEstado("estado de personaje", estadoDePersonaje);
}

void EstadoDePersonajeServidor::cambiarAnimacion(Entidad *entidad, const string &estado) {
    enum PERSONAJE personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
    auto *animacion = FabricaDeAnimacionesServidor::getAnimacion(personaje, estado);
//    delete entidad->getComportamiento<AnimacionServidor>("animacion servidor");
    entidad->agregarComportamiento("animacion servidor", animacion);
}

void EstadoDePersonajeServidor::saltar(Entidad *entidad) {
    EstadoDePersonaje *estadoDePersonaje;
    enum PERSONAJE personaje;
    AnimacionServidor *animacion;
    if (entidad->getEstado<Velocidad>("velocidad")->x == 0) {
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

    EstadoDePersonajeServidor *saltando = new Saltando();
    entidad->agregarComportamiento("estado", saltando);
}

void EstadoDePersonajeServidor::reposar(Entidad *entidad) {
    agregarEstado(entidad, REPOSANDO);

    EstadoDePersonajeServidor *reposando = new Reposando();
    entidad->agregarComportamiento("estado", reposando);

    cambiarAnimacion(entidad, "reposando");
}

void EstadoDePersonajeServidor::agachar(Entidad *entidad) {
    agregarEstado(entidad, AGACHADO);

    EstadoDePersonajeServidor *agachado = new Agachado();
    entidad->agregarComportamiento("estado", agachado);

    cambiarAnimacion(entidad, "agachado");
}

void EstadoDePersonajeServidor::caminar(Entidad *entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    agregarEstado(entidad, CAMINANDO);

    EstadoDePersonajeServidor *caminando = new Caminando();
    entidad->agregarComportamiento("estado", caminando);

    cambiarAnimacion(entidad, "caminando");
}

void EstadoDePersonajeServidor::golpear(Entidad *entidad) {
    agregarEstado(entidad, GOLPEANDO);

    EstadoDePersonajeServidor *golpeando = new Golpeando();
    entidad->agregarComportamiento("estado", golpeando);

    cambiarAnimacion(entidad, "golpeando");
}

void EstadoDePersonajeServidor::actualizar(Entidad *) {}

void EstadoDePersonajeServidor::golpeado(Entidad *entidad) {
    agregarEstado(entidad, GOLPEADO);

    EstadoDePersonajeServidor *golpeado = new Golpeado();
    entidad->agregarComportamiento("estado", golpeado);

    cambiarAnimacion(entidad, "golpeado");
}

