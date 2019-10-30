//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_NIVELSERVIDOR_H
#define FINAL_FIGHT_NIVELSERVIDOR_H


#include "../modelo/Mapa.h"
#include "../servicios/Locator.h"
#include "../modelo/serializables/Posicion.h"
#include "../modelo/Orientacion.h"
#include "../modelo/Personaje.h"
#include "../modelo/serializables/TipoElemento.h"


class NivelServidor {

private:
    static void generarTransicion(const string &nivel,Mapa *mapa, Jugadores* posicionDeJugador);
    static void generarEnemigo(const string &nivel, Mapa *mapa, Posicion *posicionDeEscenario);
    static void generarElementos(const string &nivel, Mapa *mapa, Posicion *posicionDeEscenario, elementos ART);

public:
    static void generarMenuSeleccion(Mapa *mapa);
    static Entidad *generarJugador(Mapa *mapa, enum PERSONAJE personajeSeleccionado, int numeroJugador);

    static void generarNivel(const string &nivel, Mapa *mapa);
    static Entidad *generarEscenario(const string &nivel, Mapa *mapa);
};


#endif //FINAL_FIGHT_NIVELSERVIDOR_H
