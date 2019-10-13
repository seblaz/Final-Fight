//
// Created by sebas on 8/10/19.
//

#include "ConfirmarSeleccion.h"
#include "../servidor/NivelServidor.h"
#include "../estados/Reposando.h"
#include "../fisica/FisicaDePersonaje.h"

ConfirmarSeleccion::ConfirmarSeleccion(Mapa *mapa, enum PERSONAJE personaje) :
        mapa(mapa), personajeSeleccionado(personaje) {}

void ConfirmarSeleccion::resolver() {
    mapa->vaciarMapa();


    /*
    unordered_map<IdEntidad, Entidad *> jugadores = mapa->devolverJugadores();
    if (jugadores.size() > 0) {
        for (auto &jugador: jugadores) {
            enum PERSONAJE personajeEnMapa = jugador.second->getEstado<Personaje>("personaje")->getPersonaje();
            if (personajeEnMapa == personajeSeleccionado) {
                Locator::logger()->log(ERROR, "El personaje seleccionado ya se encuentra elegido");
                NivelServidor::generarMenuSeleccion(mapa);
            } else {
                NivelServidor::generarJugador(mapa, personajeSeleccionado);
                NivelServidor::generarNivel("nivel1", mapa);
            }
        }
    } else {
        NivelServidor::generarJugador(mapa, personajeSeleccionado);
        NivelServidor::generarNivel("nivel1", mapa);
    }
    */

    if (personajeSeleccionado == GUY){
        NivelServidor::generarMenuSeleccion(mapa);
    } else {
        NivelServidor::generarJugador(mapa, personajeSeleccionado);
        NivelServidor::generarNivel("nivel1", mapa);
    }
}
