//
// Created by sebas on 8/10/19.
//

#include "ActualizadorJuego.h"
#include "../NivelServidor.h"
#include "../../modelo/Accion.h"
#include "../../eventos/EventoPersonaje.h"
#include "../../usuario/Usuario.h"
#include "../../modelo/Actividad.h"
#include "../../eventos/DesconectarVoluntariamente.h"
#include "../../modelo/EstadoDePersonaje.h"
#include "../../estados/EstadoDePersonajeServidor.h"
#include "../../estados/Reposando.h"

ActualizadorJuego::ActualizadorJuego(Mapa *mapa, EventosAProcesar *eventos, Entidad *jugador,
                                     ManagerUsuarios *managerUsuarios) :
        mapa(mapa),
        jugador(jugador),
        eventos(eventos),
        managerUsuarios(managerUsuarios) {

    Locator::logger()->log(DEBUG, "Se crea un actualizador de juego.");
}

void ActualizadorJuego::interpretarStream(stringstream &s, Usuario *usuario) {
    Accion accion;
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
            case FIN:
                Locator::logger()->log(INFO, "Se desconecta voluntariamente el usuario " + usuario->getUsuario());
                evento = new DesconectarVoluntariamente(managerUsuarios, usuario);
                eventos->push(evento);
                desconectarUsuario(usuario);
                break;
            default:
                Locator::logger()->log(ERROR, "Se recibió una acción inválida en ActualizarJuego.");
        }
    }
}

void ActualizadorJuego::actualizarJuego(Usuario *usuario) {
    do {
        stringstream s;
        if (!usuario->getSocket()->recibir(s)) {
            Locator::logger()->log(ERROR, "Se desconectó el cliente " + usuario->getUsuario() + " de forma inesperada.");
            desconectarUsuario(usuario);
        }
        interpretarStream(s, usuario);
    } while (true);
}

void ActualizadorJuego::desconectarUsuario(Usuario *usuario) {
    Locator::logger()->log(INFO, "Se termina el hilo y se desconecta al usuario.");
    usuario->desconectar();
    eventos->push(new SetActividadJugador(jugador, false));

    jugador->getComportamiento<EstadoDePersonajeServidor>("estado")->reposar(usuario->getPersonaje());

    pthread_exit(nullptr);
}

SetActividadJugador::SetActividadJugador(Entidad *jugador, bool activo) :
        activo(activo),
        jugador(jugador) {}

void SetActividadJugador::resolver() {
    jugador->getEstado<Actividad>("actividad")->activo = activo;
}