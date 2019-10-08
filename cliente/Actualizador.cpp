//
// Created by sebas on 8/10/19.
//

#include "Actualizador.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../graficos/GraficoDePantallaCompleta.h"
#include "NivelCliente.h"

Actualizador::Actualizador(Mapa *mapa) : mapa(mapa) {}

void Actualizador::actualizarEntidades(stringstream &s) {
    if (!inicio) {
        inicio = true;
        mapa->vaciarMapa();
    }

    while (s.rdbuf()->in_avail() != 0) {
        IdEntidad idEntidad = Entidad::getIdFromStream(s);
        if (!mapa->contiene(idEntidad)) {
            Locator::logger()->log(DEBUG, "El cliente no contiene la entidad: " + to_string(idEntidad) + ", por lo tanto se crea.");
            Entidad *entidad = mapa->crearEntidadConId(idEntidad);
            entidad->deserializar(s);

            auto *tipo = entidad->getEstado<Tipo>("tipo");
            switch (tipo->tipo()) {
                case PANTALLA_SELECCION:
                    NivelCliente::generarMenuSeleccion(mapa, entidad);
                    break;
                case PERSONAJE:
                    break;
                case ESCENARIO:
                    break;
            }
        } else {
            Entidad *entidad = mapa->getEntidad(idEntidad);
            entidad->deserializar(s);
        }
    }
}
