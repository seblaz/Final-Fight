//
// Created by sebas on 8/10/19.
//

#include "ActualizadorJuego.h"
#include "../NivelServidor.h"
#include "../../modelo/Accion.h"
#include "../../eventos/ConfirmarSeleccion.h"
#include "../../eventos/EventoPersonaje.h"

ActualizadorJuego::ActualizadorJuego(Mapa *mapa, EventosAProcesar *eventos) :
        mapa(mapa),
        eventos(eventos) {}

void ActualizadorJuego::interpretarStream(stringstream &s) {

    Accion accion;
    Entidad *jugador = mapa->getJugador();
    while (s.rdbuf()->in_avail() != 0) {
        accion.deserializar(s);

        EventoAProcesar *evento;
        switch (accion.accion()) {
            case GOLPEAR:
                evento = new Golpear(jugador);
                eventos->push(evento);
                break;
            case SALTAR:
                evento = new Saltar(jugador);
                eventos->push(evento);
                break;
            case REPOSAR:
                evento = new Reposar(jugador);
                eventos->push(evento);
                break;
            case AGACHAR:
                evento = new Agachar(jugador);
                eventos->push(evento);
                break;
            case CAM_IZQUIERDA:
                evento = new CaminarIzquierda(jugador);
                eventos->push(evento);
                break;
            case CAM_DERECHA:
                evento = new CaminarDerecha(jugador);
                eventos->push(evento);
                break;
            case CAM_ARRIBA:
                evento = new CaminarArriba(jugador);
                eventos->push(evento);
                break;
            case CAM_ABAJO:
                evento = new CaminarAbajo(jugador);
                eventos->push(evento);
                break;
            case CAM_IZQUIERDA_ARRIBA:
                evento = new CaminarIzquierdaArriba(jugador);
                eventos->push(evento);
                break;
            case CAM_IZQUIERDA_ABAJO:
                evento = new CaminarIzquierdaAbajo(jugador);
                eventos->push(evento);
                break;
            case CAM_DERECHA_ARRIBA:
                evento = new CaminarDerechaArriba(jugador);
                eventos->push(evento);
                break;
            case CAM_DERECHA_ABAJO:
                evento = new CaminarDerechaAbajo(jugador);
                eventos->push(evento);
                break;
            default:
                Locator::logger()->log(ERROR, "Se recibió una acción inválida en ActualizarJuego.");
                fin_ = true;
        }
    }
}

bool ActualizadorJuego::fin() {
    return fin_;
}
