//
// Created by sebas on 6/11/19.
//

#include "InterpreteJuegoCli.h"
#include "../../modelo/Entidad.h"
#include "../../servicios/Locator.h"
#include "../NivelCliente.h"

void InterpreteJuegoCli::interpretar(stringstream &s) {
    Mapa *mapa = Locator::mapa();
    while (s.rdbuf()->in_avail() != 0) {

        IdEntidad idEntidad = Entidad::getIdFromStream(s);
        if (!mapa->contiene(idEntidad)) {
            Entidad *entidad = mapa->crearEntidadConId(idEntidad);
            entidad->deserializar(s);
            Posicion *posicion;
            auto *tipo = entidad->getEstado<Tipo>("tipo");
            switch (tipo->tipo()) {
                case JUGADOR:
                    mapa->agregarJugadorConId(idEntidad, entidad);
                    NivelCliente::generarJugador(mapa, idEntidad, entidad);
                    break;
                case ESCENARIO:
                    posicion = entidad->getEstado<Posicion>("posicion");
                    Locator::provide(posicion);
                    NivelCliente::generarEscenario(mapa, entidad);
                    break;
                case TRANSICION:
                    NivelCliente::generarTransicion(mapa, entidad);
                    break;
                case ENEMIGO:
                    NivelCliente::generarEnemigo(mapa, entidad);
                    break;
                case ELEMENTO:
                    NivelCliente::generarElemento(mapa, entidad);
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
