//
// Created by leo on 15/11/19.
//

#include "NotificadorDeGolpesJugador.h"
#include "../../modelo/serializables/Puntaje.h"
#include "../../modelo/serializables/EstadoDePersonaje.h"
#include "../../modelo/serializables/Arma.h"
#include "../../modelo/serializables/Energia.h"
#include "../../servicios/Locator.h"
#include "../../modelo/serializables/Elemento.h"

NotificadorDeGolpesJugador::NotificadorDeGolpesJugador(Entidad *jugador) : jugador(jugador) {}

void NotificadorDeGolpesJugador::notificarGolpeAPersonaje(Entidad* personajeGolpeado){
    auto estadoGolpeador = jugador->getEstado<EstadoDePersonaje>("estado de personaje");
    auto puntajeGolpeador = jugador->getEstado<Puntaje>("puntaje");
    auto arma = jugador->getEstado<Arma>("arma");

    string tipoArma = Arma::armaACadena(arma->getArma());
    int puntosArma = Locator::configuracion()->getIntValue("/armas/" + tipoArma + "/puntos");

    int puntosParaJugador = estadoGolpeador->getEstado() == PATEANDO ? 400 : puntosArma;
    puntajeGolpeador->agregarPuntos(puntosParaJugador);

    if(!personajeGolpeado->getEstado<Energia>("energia")->personajeVive()){
        puntajeGolpeador->agregarPuntos(500);
    }
}

void NotificadorDeGolpesJugador::notificarGolpeAElemento(Elemento *elemento) {
    if(elemento->estaRoto()){
        string tipoElemento = Elemento::ElementoACadena(elemento->getElemento());
        int puntos = Locator::configuracion()->getIntValue("/elementos/" + tipoElemento + "/puntos");
        jugador->getEstado<Puntaje>("puntaje")->agregarPuntos(puntos);
    }
}
