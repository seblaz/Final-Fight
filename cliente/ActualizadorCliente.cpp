//
// Created by sebas on 8/10/19.
//

#include <unordered_set>
#include "ActualizadorCliente.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../graficos/GraficoDePantallaCompleta.h"
#include "NivelCliente.h"

ActualizadorCliente::ActualizadorCliente(Mapa *mapa) : mapa(mapa) {}

void ActualizadorCliente::actualizarEntidades(stringstream &s, TrasmisionCliente *transmision) {
    if (borrar) {
        borrar = false;
        mapa->vaciarMapa();
    }

    unordered_set<IdEntidad> nuevasEntidades;

    nuevasEntidades.clear();

    while (s.rdbuf()->in_avail() != 0) {
        IdEntidad idEntidad = Entidad::getIdFromStream(s);
//        Locator::logger()->log(DEBUG, "Se recibe la entidad " + to_string(idEntidad));
        nuevasEntidades.insert(idEntidad);
        if (!mapa->contiene(idEntidad)) {
            Entidad *entidad = mapa->crearEntidadConId(idEntidad);
            entidad->deserializar(s);
            Posicion *posicion;
            auto *tipo = entidad->getEstado<Tipo>("tipo");
            switch (tipo->tipo()) {
                case PANTALLA_SELECCION:
                    transmision->setEntradaUsuario(new EntradaMenuSeleccion);
                    NivelCliente::generarMenuSeleccion(mapa, entidad);
                    break;
                case JUGADOR:
                    mapa->agregarJugadorConId(idEntidad, entidad);
                    NivelCliente::generarJugador(mapa, idEntidad, entidad);
                    break;
                case PERSONAJE_SELECCION:
                    NivelCliente::generarSelectorDePersonaje(mapa, entidad);
                    break;
                case ESCENARIO:
                    posicion = entidad->getEstado<Posicion>("posicion");
                    Locator::provide(posicion);
                    transmision->setEntradaUsuario(new EntradaJuego);
                    NivelCliente::generarEscenario(mapa, entidad);
                    break;
                default:
                    Locator::logger()->log(ERROR, "Se recibió una entidad de tipo desconocida.");
            }
        } else {
            Entidad *entidad = mapa->getEntidad(idEntidad);
            entidad->deserializar(s);
        }
    }

    for (auto tupla : mapa->devolverEntidadesConId()) {
        if (nuevasEntidades.find(tupla.first) == nuevasEntidades.end()) {
            mapa->quitarEntidad(tupla.first);
        }
    }
}
