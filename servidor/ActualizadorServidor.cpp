//
// Created by sebas on 8/10/19.
//

#include "ActualizadorServidor.h"
#include "NivelServidor.h"
#include "../modelo/Accion.h"
#include "../eventos/ConfirmarSeleccion.h"

ActualizadorServidor::ActualizadorServidor(Mapa *mapa, EventosAProcesar *eventos) :
        mapa(mapa),
        eventos(eventos) {}

void ActualizadorServidor::interpretarComando(stringstream &s) {

    Accion accion;

    while (s.rdbuf()->in_avail() != 0) {
        accion.deserializar(s);

        switch (accion.accion()) {
            case CONFIRMAR:
                auto *evento = new ConfirmarSeleccion(mapa);
                eventos->push(evento);
                break;
//            case SELECCIONAR_SIGUIENTE:
//                break;
//            case SELECCIONAR_ANTERIOR:
//                break;
        }
    }
}
