//
// Created by sebas on 9/10/19.
//

#include "EventoPersonaje.h"
#include "../estados/EstadoDePersonaje.h"

EventoPersonaje::EventoPersonaje(Entidad *personaje) : personaje(personaje) {}

void Reposar::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->reposar(personaje);
}

void Saltar::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->saltar(personaje);
}

void Golpear::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->golpear(personaje);
}

void Agachar::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->agachar(personaje);
}

void CaminarIzquierda::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->caminar(personaje, 0, 1, 0, 0);
}

void CaminarDerecha::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->caminar(personaje, 1, 0, 0, 0);
}

void CaminarArriba::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->caminar(personaje, 0, 0, 1, 0);
}

void CaminarAbajo::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->caminar(personaje, 0, 0, 0, 1);
}

void CaminarIzquierdaArriba::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->caminar(personaje, 0, 1, 1, 0);
}

void CaminarIzquierdaAbajo::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->caminar(personaje, 0, 1, 0, 1);
}

void CaminarDerechaArriba::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->caminar(personaje, 1, 0, 1, 0);
}

void CaminarDerechaAbajo::resolver() {
    personaje->getEstado<EstadoDePersonaje>("estado")->caminar(personaje, 1, 0, 0, 1);
}
