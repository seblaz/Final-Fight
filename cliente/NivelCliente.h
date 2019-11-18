//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_NIVELCLIENTE_H
#define FINAL_FIGHT_NIVELCLIENTE_H


#include "../modelo/Mapa.h"
#include "../modelo/serializables/Posicion.h"

class NivelCliente {

public:
    static void generarJugador(Entidad *jugador);
    static void generarEscenario(Entidad *escenario);
    static void generarTransicion(Entidad *transicion);
    static void generarEnemigo(Entidad *enemigo);
    static void generarElemento(Entidad *entidad);

    static void generarArma(Entidad *arma);
};


#endif //FINAL_FIGHT_NIVELCLIENTE_H
