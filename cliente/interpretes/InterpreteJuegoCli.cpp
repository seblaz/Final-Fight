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
                case TIPO::JUGADOR:
                    mapa->agregarJugadorConId(idEntidad, entidad);
                    NivelCliente::generarJugador(entidad);
                    break;
                case TIPO::ESCENARIO:
                    posicion = entidad->getEstado<Posicion>("posicion");
                    Locator::provide(posicion);
                    NivelCliente::generarEscenario(entidad);
                    break;
                case TIPO::TRANSICION:
                    NivelCliente::generarTransicion(entidad);
                    break;
                case TIPO::ENEMIGO:
                    NivelCliente::generarEnemigo(entidad);
                    break;
                case TIPO::ELEMENTO_GOLPEABLE:
                    NivelCliente::generarElemento(entidad);
                    break;
                case TIPO::ARMA:
                    NivelCliente::generarArma(entidad);
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
