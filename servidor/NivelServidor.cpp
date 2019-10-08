//
// Created by sebas on 6/10/19.
//

#include "NivelServidor.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"
#include "../modelo/Orientacion.h"

void NivelServidor::generarMenuSeleccion(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se genera el menu de seleccion.");

    Entidad *pantalla = mapa->crearEntidad();
    auto *posicion = new Posicion(10, 20, 50);
    auto *tipo = new Tipo(PANTALLA_SELECCION);

    pantalla->agregarEstado("posicion", posicion);
    pantalla->agregarEstado("mapa", mapa);
    pantalla->agregarEstado("tipo", tipo);
}

void NivelServidor::generarJugador(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se genera jugador.");

    auto* jugador = mapa->crearJugador();
    auto* posicion = new Posicion(200, 100, 0);
    auto *velocidad = new Velocidad();
    auto *orientacion = new Orientacion;
    auto *tipo = new Tipo(JUGADOR);
//    EstadoDePersonaje *estado = new Reposando();
//    auto *fisica = new FisicaDePersonaje();
//    auto *entradaJugador = new EntradaJugador();

    jugador->agregarEstado("tipo", tipo);
    jugador->agregarEstado("posicion", posicion);
    jugador->agregarEstado("velocidad", velocidad);
    jugador->agregarEstado("orientacion", orientacion);
//    jugador->agregarEstado("estado", estado);
//    jugador->agregarComportamiento("fisica", fisica);
//    jugador->agregarComportamiento("entrada jugador", entradaJugador);
}
