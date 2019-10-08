//
// Created by sebas on 8/10/19.
//

#include "ActualizadorCliente.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../graficos/GraficoDePantallaCompleta.h"
#include "NivelCliente.h"

ActualizadorCliente::ActualizadorCliente(Mapa *mapa) : mapa(mapa) {}

void ActualizadorCliente::actualizarEntidades(stringstream &s) {
    if (!inicio) {
        inicio = true;
        mapa->vaciarMapa();
    }

    while (s.rdbuf()->in_avail() != 0) {
        IdEntidad idEntidad = Entidad::getIdFromStream(s);
        if (!mapa->contiene(idEntidad)) {
            Locator::logger()->log(DEBUG, "El cliente no contiene la entidad: " + to_string(idEntidad) + ", por lo tanto se crea y se borran las anteriores.");
            mapa->vaciarMapa();
            Entidad *entidad = mapa->crearEntidadConId(idEntidad);
            entidad->deserializar(s);

            auto *tipo = entidad->getEstado<Tipo>("tipo");
            switch (tipo->tipo()) {
                case PANTALLA_SELECCION:
                    NivelCliente::generarMenuSeleccion(mapa, entidad);
                    break;
                case JUGADOR:
                    mapa->agregarJugadorConId(idEntidad, entidad);
                    NivelCliente::generarJugador(mapa, idEntidad, entidad);
                    break;
                case ESCENARIO:
                    break;
                default:
                    Locator::logger()->log(ERROR, "Se recibió una entidad de tipo desconocida.");
            }
        } else {
            Entidad *entidad = mapa->getEntidad(idEntidad);
            entidad->deserializar(s);
        }
    }
}
