//
// Created by sebas on 8/10/19.
//

#include "ActualizadorServidor.h"
#include "NivelServidor.h"
#include "../modelo/Accion.h"
#include "../eventos/SeleccionarCody.h"

ActualizadorServidor::ActualizadorServidor(Mapa *mapa, EventosAProcesar *eventos) :
        mapa(mapa),
        eventos(eventos) {}

void ActualizadorServidor::interpretarComando(stringstream &s) {

    Accion accion;
    accion.deserializar(s);

    switch (accion.accion()) {
        case SELECCIONAR_CODY:
            auto *evento = new SeleccionarCody(mapa);
            eventos->push(evento);
            break;
    }
}
