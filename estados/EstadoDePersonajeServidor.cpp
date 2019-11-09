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
#include "Golpeado.h"
#include "../eventos/EventoPersonaje.h"

template<typename T>
EstadoDePersonajeServidor *crearEstado() { return new T; }

map<ESTADO_DE_PERSONAJE, EstadoDePersonajeServidor *(*)()> EstadoDePersonajeServidor::mapa = {
        {CAMINANDO, &crearEstado<Caminando>},
        {AGACHADO, &crearEstado<Agachado>},
        {REPOSANDO, &crearEstado<Reposando>},
        {SALTANDO, &crearEstado<Saltando>},
        {SALTANDO_CON_MOVIMIENTO, &crearEstado<Saltando>},
        {GOLPEANDO, &crearEstado<Golpeando>},
        {GOLPEADO, &crearEstado<Golpeado>},
};

void EstadoDePersonajeServidor::cambiarEstado(Entidad *entidad, ESTADO_DE_PERSONAJE estado) {
    entidad->agregarEstado("estado de personaje", new EstadoDePersonaje(estado));
    entidad->agregarComportamiento("estado", mapa[estado]());

    enum PERSONAJE personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
    auto *animacion = FabricaDeAnimacionesServidor::getAnimacion(personaje, estado);
//    delete entidad->getComportamiento<AnimacionServidor>("animacion servidor");
    entidad->agregarComportamiento("animacion servidor", animacion);
}

void EstadoDePersonajeServidor::saltar(Entidad *entidad) {
    if (entidad->getEstado<Velocidad>("velocidad")->x == 0)
        cambiarEstado(entidad, SALTANDO);
    else
        cambiarEstado(entidad, SALTANDO_CON_MOVIMIENTO);
}

void EstadoDePersonajeServidor::reposar(Entidad *entidad) {
    cambiarEstado(entidad, REPOSANDO);
}

void EstadoDePersonajeServidor::agachar(Entidad *entidad) {
    cambiarEstado(entidad, AGACHADO);
}

void EstadoDePersonajeServidor::caminar(Entidad *entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    cambiarEstado(entidad, CAMINANDO);
    entidad->getComportamiento<EstadoDePersonajeServidor>("estado")->caminar(entidad, X_pos, X_neg, Y_pos, Y_neg);
}

void EstadoDePersonajeServidor::golpear(Entidad *entidad) {
    cambiarEstado(entidad, GOLPEANDO);
}

void EstadoDePersonajeServidor::actualizar(Entidad * entidad) {
    // Si quedó en este estado por más de un frame quiere decir que se desconectó el usuario.
    // Entonces lo paso a reposar.
    frames++;
    if(frames > 1)
        Locator::eventos()->push(new Reposar(entidad));
}

void EstadoDePersonajeServidor::golpeado(Entidad *entidad) {
    cambiarEstado(entidad, GOLPEADO);
}
