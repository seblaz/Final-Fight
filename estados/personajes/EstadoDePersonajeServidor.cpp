//
// Created by sebas on 21/9/19.
//

#include "EstadoDePersonajeServidor.h"
#include "../../servicios/Locator.h"
#include "Saltando.h"
#include "Caminando.h"
#include "Agachado.h"
#include "DandoGolpe.h"
#include "../../servidor/FabricaDeAnimacionesServidor.h"
#include "RecibiendoGolpe.h"
#include "../../eventos/EventoPersonaje.h"
#include "../../modelo/serializables/IndiceSprite.h"
#include "../../modelo/serializables/Arma.h"
#include "../../modelo/serializables/Puntaje.h"
#include "../../modelo/serializables/Energia.h"
#include "../../servidor/notificadores/NotificadorDeGolpesJugador.h"
#include "Muerto.h"

EstadoDePersonajeServidor::EstadoDePersonajeServidor(Entidad *entidad) : EstadoDeColisionable(entidad) {
    auto *estadoDePersonaje = entidad->getEstado<EstadoDePersonaje>("estado de personaje");
    string estado = estadoDePersonaje ? EstadoDePersonaje::estadoACadena(estadoDePersonaje->getEstado()) : "reposando";
    auto *personaje = entidad->getEstado<Personaje>("personaje");
    string nombrePersonaje = estadoDePersonaje ? Personaje::PersonajeACadena(personaje->getPersonaje()) : "cody";
    framesFaltantes = Locator::configuracion()->getIntValue("/animaciones/" + nombrePersonaje + "/" + estado + "/total");
}

template<typename T>
EstadoDePersonajeServidor *crearEstado(Entidad *entidad) { return new T(entidad); }

map<ESTADO_DE_PERSONAJE, EstadoDePersonajeServidor *(*)(Entidad *entidad)> EstadoDePersonajeServidor::mapa = {
        {CAMINANDO,               &crearEstado<Caminando>},
        {AGACHADO,                &crearEstado<Agachado>},
        {REPOSANDO,               &crearEstado<Reposando>},
        {SALTANDO,                &crearEstado<Saltando>},
        {SALTANDO_CON_MOVIMIENTO, &crearEstado<Saltando>},
        {DANDO_GOLPE,             &crearEstado<DandoGolpe>},
        {RECIBIENDO_GOLPE,        &crearEstado<RecibiendoGolpe>},
        {MUERTO,                  &crearEstado<Muerto>},
};

void EstadoDePersonajeServidor::cambiarEstado(ESTADO_DE_PERSONAJE estado) {
    enum PERSONAJE personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
    auto *animacion = FabricaDeAnimacionesServidor::getAnimacion(entidad, personaje, estado);
    entidad->agregarComportamiento("animacion servidor", animacion);
    entidad->getEstado<IndiceSprite>("indice sprite")->setIndice(0);

    entidad->agregarEstado("estado de personaje", new EstadoDePersonaje(estado));
    entidad->agregarComportamiento("estado", mapa[estado](entidad));
}

void EstadoDePersonajeServidor::saltar() {
    if (entidad->getEstado<Velocidad>("velocidad")->x == 0)
        cambiarEstado(SALTANDO);
    else
        cambiarEstado(SALTANDO_CON_MOVIMIENTO);
}

void EstadoDePersonajeServidor::reposar() {
    cambiarEstado(REPOSANDO);
}

void EstadoDePersonajeServidor::agachar() {
    cambiarEstado(AGACHADO);
}

void EstadoDePersonajeServidor::caminar(bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    cambiarEstado(CAMINANDO);
}

void EstadoDePersonajeServidor::darGolpe() {
    cambiarEstado(DANDO_GOLPE);
}

void EstadoDePersonajeServidor::recibirGolpeDe(Entidad *golpeador) {
    Locator::logger()->log(INFO, "Un personaje recibió un golpe.");
    auto *energiaGolpeado = this->entidad->getEstado<Energia>("energia");
    auto *arma = golpeador->getEstado<Arma>("arma");
    energiaGolpeado->restarEnergia(arma->getPuntosDeDanio());
    golpeador->getEstado<NotificadorDeGolpes>("notificador")->notificarGolpeAPersonaje(this->entidad);
    arma->usar();
    cambiarEstado(RECIBIENDO_GOLPE);
}

void EstadoDePersonajeServidor::actualizar() {
    // Si quedó en este estado por más de un frame quiere decir que se desconectó el usuario.
    // Entonces lo paso a reposar.
    if(frames++ > 1)
        Locator::eventos()->push(new Reposar(entidad));
}

void EstadoDePersonajeServidor::morir() {
    Locator::mapa()->quitarEnemigo(entidad);
    cambiarEstado(MUERTO);
}
