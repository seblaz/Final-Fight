//
// Created by sebas on 12/10/19.
//

#include "ActualizadorMenuSeleccion.h"


ActualizadorMenuSeleccion::ActualizadorMenuSeleccion(Mapa *mapa, EventosAProcesar *eventos) :
        mapa(mapa),
        eventos(eventos) {}

void ActualizadorMenuSeleccion::interpretarStream(stringstream &s) {
    Accion accion;
    while (s.rdbuf()->in_avail() != 0) {
        accion.deserializar(s);

        EventoAProcesar *evento;
        switch (accion.accion()) {
            // TODO: utilizar la clase que maneja las selecciones.
            case CONFIRMAR:
                evento = new ConfirmarSeleccion(mapa);
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