//
// Created by sebas on 6/10/19.
//

#include "NivelServidor.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"

void NivelServidor::generarMenuSeleccion(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se genera el menu de seleccion.");

    Entidad *pantalla = mapa->crearEntidad();
    auto *posicion = new Posicion(10, 20, 50);
    auto *tipo = new Tipo(PANTALLA_SELECCION);

    pantalla->agregarEstado("posicion", posicion);
    pantalla->agregarEstado("mapa", mapa);
    pantalla->agregarEstado("tipo", tipo);
}
