//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_NIVELSERVIDOR_H
#define FINAL_FIGHT_NIVELSERVIDOR_H


#include "../modelo/Mapa.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"
#include "../modelo/Orientacion.h"
#include "../modelo/Personaje.h"


class NivelServidor {

public:
    static void generarMenuSeleccion(Mapa *mapa);
    static Entidad * generarJugador(Mapa *mapa);

    static void generarPersonajesSeleccion(Mapa *mapa);
    static void generarNivel(const string &nivel, Mapa *mapa);

    static Entidad *generarEscenario(const string &nivel, Mapa *mapa);
};


#endif //FINAL_FIGHT_NIVELSERVIDOR_H
