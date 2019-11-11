//
// Created by sebas on 21/9/19.
//

#include "EstadoDePersonajeServidor.h"
#include "../servicios/Locator.h"
#include "Saltando.h"
#include "Caminando.h"
#include "Agachado.h"
#include "DandoGolpe.h"
#include "../servidor/FabricaDeAnimacionesServidor.h"
#include "RecibiendoGolpe.h"
#include "../eventos/EventoPersonaje.h"

template<typename T>
EstadoDePersonajeServidor *crearEstado() { return new T; }

map<ESTADO_DE_PERSONAJE, EstadoDePersonajeServidor *(*)()> EstadoDePersonajeServidor::mapa = {
        {CAMINANDO,               &crearEstado<Caminando>},
        {AGACHADO,                &crearEstado<Agachado>},
        {REPOSANDO,               &crearEstado<Reposando>},
        {SALTANDO,                &crearEstado<Saltando>},
        {SALTANDO_CON_MOVIMIENTO, &crearEstado<Saltando>},
        {DANDO_GOLPE,             &crearEstado<DandoGolpe>},
        {RECIBIENDO_GOLPE,        &crearEstado<RecibiendoGolpe>},
};

void EstadoDePersonajeServidor::cambiarEstado(Entidad *entidad, ESTADO_DE_PERSONAJE estado) {
    entidad->agregarEstado("estado de personaje", new EstadoDePersonaje(estado));
    entidad->agregarComportamiento("estado", mapa[estado]());

    enum PERSONAJE personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
    auto *animacion = FabricaDeAnimacionesServidor::getAnimacion(personaje, estado);
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

void EstadoDePersonajeServidor::darGolpe(Entidad *entidad) {
    cambiarEstado(entidad, DANDO_GOLPE);
}

void EstadoDePersonajeServidor::recibirGolpe(Entidad *entidad) {
    cambiarEstado(entidad, RECIBIENDO_GOLPE);
}

void EstadoDePersonajeServidor::actualizar(Entidad * entidad) {
    // Si quedó en este estado por más de un frame quiere decir que se desconectó el usuario.
    // Entonces lo paso a reposar.
    frames++;
    if(frames > 1)
        Locator::eventos()->push(new Reposar(entidad));
}
