//
// Created by sebas on 12/10/19.
//

#include "ActualizadorMenuSeleccion.h"
#include "../NivelServidor.h"
#include "../../usuario/Usuario.h"

ConfirmarSeleccion::ConfirmarSeleccion(SelectorPersonajes *selector, Mapa *mapa, ManagerUsuarios *manager,
                                       semaphore *confirmacion) :
        confirmacion(confirmacion),
        selector(selector),
        manager(manager),
        mapa(mapa) {}

void ConfirmarSeleccion::resolver() {
    selector->confirmar();
    if(selector->puedoComenzar()){
        for(Usuario *usuario : manager->getUsuarios()){
            Entidad *personaje = NivelServidor::generarJugador(mapa);
            usuario->setPersonaje(personaje);
        }
        NivelServidor::generarNivel("nivel1", mapa);
        for(int i = 0; i < manager->cantidadJugadoresTotales(); i++){
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
        confirmacion(confirmacion){}

void ActualizadorMenuSeleccion::interpretarStream(stringstream &s) {
    Accion accion;
    while (s.rdbuf()->in_avail() != 0) {
        accion.deserializar(s);

        EventoAProcesar *evento;
        switch (accion.accion()) {
            case CONFIRMAR:
                evento = new ConfirmarSeleccion(selector, mapa, manager, confirmacion);
                eventos->push(evento);
                fin_ = true;
                break;
            case SELECCIONAR_SIGUIENTE:
                break;
            case SELECCIONAR_ANTERIOR:
                break;
            default:
                Locator::logger()->log(ERROR, "El actualizador del menu de selección recibió una acción inválida.");
        }
    }
}

bool ActualizadorMenuSeleccion::fin() {
    return fin_;
}

