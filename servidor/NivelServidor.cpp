//
// Created by sebas on 6/10/19.
//

#include "NivelServidor.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"

void NivelServidor::generarMenuSeleccion(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se genera el menu de seleccion.");

    Entidad *pantalla = mapa->crearEntidad();
    auto *posicion = new Posicion(0, 0, 0);

    pantalla->agregarEstado("posicion", posicion);
    pantalla->agregarEstado("mapa", mapa);
}
