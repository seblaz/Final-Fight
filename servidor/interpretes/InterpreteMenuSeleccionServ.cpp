//
// Created by sebas on 5/11/19.
//

#include "InterpreteMenuSeleccionServ.h"
#include "../../servicios/Locator.h"
#include "../NivelServidor.h"

bool InterpreteMenuSeleccionServ::interpretarAccion(ACCION accion, stringstream &s) {
    auto *evento = new ConfirmarSeleccion(getUsuario(), static_cast<enum PERSONAJE>(accion - SELECCIONAR_GUY));
    Locator::eventos()->push(evento);
    return true;
}

void InterpreteMenuSeleccionServ::finalizarCliente() {
    getUsuario()->desconectar();
    getUsuario()->setPersonajeSeleccionado(NULO);
}

ConfirmarSeleccion::ConfirmarSeleccion(Usuario *usuario, enum PERSONAJE personaje) :
        usuario(usuario),
        personajeSeleccionado(personaje) {}

void ConfirmarSeleccion::resolver() {
    usuario->setPersonajeSeleccionado(personajeSeleccionado);
    bool listos = true;
    for(auto *iUsuario : Locator::usuarios()->getUsuarios()){
        if(iUsuario->getPersonajeSeleccionado() == NULO || !iUsuario->estaConectado()){
            listos = false;
            break;
        }
    }
    if(listos && !Locator::usuarios()->faltanJugadores()){
        int numeroJugador = 1;
        for (Usuario *iUsuario : Locator::usuarios()->getUsuarios()) {
            Entidad *personaje = NivelServidor::generarJugador(Locator::mapa(), iUsuario->getPersonajeSeleccionado(), numeroJugador);
            iUsuario->setPersonaje(personaje);
            numeroJugador++;
        }
        NivelServidor::generarNivel("nivel1", Locator::mapa());
        Locator::clientes()->cambiarTodosA("nivel1");
    }
}