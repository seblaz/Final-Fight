//
// Created by sebas on 5/11/19.
//

#include "InterpreteJuegoServ.h"
#include "../../servicios/Locator.h"
#include "../../eventos/EventoPersonaje.h"
#include "../../modelo/serializables/Actividad.h"

bool InterpreteJuegoServ::interpretarAccion(ACCION accion, stringstream &s) {
    EventoAProcesar *evento;
    Entidad *jugador = getUsuario()->getPersonaje();
    switch (accion) {
        case GOLPEAR:
            evento = new Golpear(jugador);
            break;
        case SALTAR:
            evento = new Saltar(jugador);
            break;
        case REPOSAR:
            evento = new Reposar(jugador);
            break;
        case AGACHAR:
            evento = new Agachar(jugador);
            break;
        case CAM_IZQUIERDA:
            evento = new CaminarIzquierda(jugador);
            break;
        case CAM_DERECHA:
            evento = new CaminarDerecha(jugador);
            break;
        case CAM_ARRIBA:
            evento = new CaminarArriba(jugador);
            break;
        case CAM_ABAJO:
            evento = new CaminarAbajo(jugador);
            break;
        case CAM_IZQUIERDA_ARRIBA:
            evento = new CaminarIzquierdaArriba(jugador);
            break;
        case CAM_IZQUIERDA_ABAJO:
            evento = new CaminarIzquierdaAbajo(jugador);
            break;
        case CAM_DERECHA_ARRIBA:
            evento = new CaminarDerechaArriba(jugador);
            break;
        case CAM_DERECHA_ABAJO:
            evento = new CaminarDerechaAbajo(jugador);
            break;
        case MODOTEST:
            Locator::logger()->log(INFO, "Se cambia el modo test del usuario " + getUsuario()->getUsuario() + ".");
            evento = new ModoTest(jugador);
            break;
        default:
            Locator::logger()->log(ERROR, "Se recibió una acción inválida en ActualizarJuego.");
            return true;
    }
    Locator::eventos()->push(evento);
    return true;
}

void InterpreteJuegoServ::iniciar() {
    getUsuario()->getPersonaje()->getEstado<Actividad>("actividad")->activo = true;
}

void InterpreteJuegoServ::finalizarCliente() {
    getUsuario()->desconectar();
    getUsuario()->getPersonaje()->getEstado<Actividad>("actividad")->activo = false;
}

