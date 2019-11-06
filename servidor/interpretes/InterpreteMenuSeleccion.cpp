//
// Created by sebas on 5/11/19.
//

#include "InterpreteMenuSeleccion.h"
#include "../../servicios/Locator.h"
#include "../SelectorPersonajes.h"
#include "../NivelServidor.h"

bool InterpreteMenuSeleccion::interpretarAccion(ACCION accion, stringstream &s) {
    auto *evento = new ConfirmarSeleccion(getUsuario(), static_cast<enum PERSONAJE>(accion - SELECCIONAR_GUY));
    Locator::eventos()->push(evento);
}

void InterpreteMenuSeleccion::finalizar() {
    getUsuario()->desconectar();
    getUsuario()->setPersonajeSeleccionado(PERSONAJE::NULO);
}

ConfirmarSeleccion::ConfirmarSeleccion(Usuario *usuario, enum PERSONAJE personaje) :
        usuario(usuario),
        personajeSeleccionado(personaje) {}

void ConfirmarSeleccion::resolver() {
    usuario->setPersonajeSeleccionado(personajeSeleccionado);
    bool listos = true;
    for(auto *iUsuario : Locator::usuarios()->getUsuarios()){
        if(iUsuario->getPersonajeSeleccionado() == PERSONAJE::NULO){
            listos = false;
            break;
        }
    }
    if(listos){
        int numeroJugador = 1;
        for (Usuario *iUsuario : Locator::usuarios()->getUsuarios()) {
            Entidad *personaje = NivelServidor::generarJugador(Locator::mapa(), iUsuario->getPersonajeSeleccionado(), numeroJugador);
            usuario->setPersonaje(personaje);
//            if(!usuario->estaConectado()){
//                personaje->getEstado<Actividad>("actividad")->activo = false;
//            }
            numeroJugador++;
        }
        NivelServidor::generarNivel("nivel1", Locator::mapa());
    }
}