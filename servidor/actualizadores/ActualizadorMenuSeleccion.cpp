//
// Created by sebas on 12/10/19.
//

#include "ActualizadorMenuSeleccion.h"
#include "../NivelServidor.h"
#include "../../usuario/Usuario.h"
#include "../../eventos/MostrarMenuSeleccion.h"

ConfirmarSeleccion::ConfirmarSeleccion(SelectorPersonajes *selector, Mapa *mapa, ManagerUsuarios *manager,
                                       enum PERSONAJE personaje_, Usuario *usuario_,
                                       semaphore *confirmacion) :
        confirmacion(confirmacion),
        selector(selector),
        manager(manager),
        mapa(mapa),
        usuario(usuario_),
        personajeSeleccionado(personaje_) {}

void ConfirmarSeleccion::resolver() {
    usuario->setPersonajeSeleccionado(personajeSeleccionado);
    selector->confirmar();
    if (selector->puedoComenzar()) {
        for (Usuario *usuario : manager->getUsuarios()) {
            Entidad *personaje = NivelServidor::generarJugador(mapa, usuario->getPersonajeSeleccionado());
            usuario->setPersonaje(personaje);
        }
        NivelServidor::generarNivel("nivel1", mapa);
        for (int i = 0; i < manager->cantidadJugadoresTotales(); i++) {
            confirmacion->post();
        }
    }
}

ActualizadorMenuSeleccion::ActualizadorMenuSeleccion(Mapa *mapa, EventosAProcesar *eventos,
                                                     SelectorPersonajes *selector, Usuario *usuario,
                                                     ManagerUsuarios *manager, semaphore *confirmacion) :
        mapa(mapa),
        usuario(usuario),
        eventos(eventos),
        manager(manager),
        selector(selector),
        confirmacion(confirmacion) {}

void ActualizadorMenuSeleccion::interpretarStream(stringstream &s) {
    Accion accion;
    while (s.rdbuf()->in_avail() != 0) {
        accion.deserializar(s);
        EventoAProcesar *evento;
        switch (accion.accion()) {
            case SELECCIONAR_GUY:
                Locator::logger()->log(DEBUG, "Se selecciono a GUY");
                evento = new ConfirmarSeleccion(selector, mapa, manager, GUY, usuario, confirmacion);
                eventos->push(evento);
                fin_ = true;
                break;
            case SELECCIONAR_MAKI:
                Locator::logger()->log(DEBUG, "Se selecciono a MAKI");
                evento = new ConfirmarSeleccion(selector, mapa, manager, MAKI, usuario, confirmacion);
                eventos->push(evento);
                fin_ = true;
                break;
            case SELECCIONAR_CODY:
                Locator::logger()->log(DEBUG, "Se selecciono a CODY");
                evento = new ConfirmarSeleccion(selector, mapa, manager, CODY, usuario, confirmacion);
                eventos->push(evento);
                fin_ = true;
                break;
            case SELECCIONAR_HAGGAR:
                Locator::logger()->log(DEBUG, "Se selecciono a HAGGAR");
                evento = new ConfirmarSeleccion(selector, mapa, manager, HAGGAR, usuario, confirmacion);
                eventos->push(evento);
                fin_ = true;
                break;
            default:
                Locator::logger()->log(ERROR, "El actualizador del menu de selección recibió una acción inválida.");
        }
    }
}


bool ActualizadorMenuSeleccion::fin() {
    return fin_;
}

