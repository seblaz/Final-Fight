//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_NIVELCLIENTE_H
#define FINAL_FIGHT_NIVELCLIENTE_H


#include "../modelo/Mapa.h"

class NivelCliente {

public:
    static void generarPantallaDeEspera(Mapa *mapa);
    static void generarMenuSeleccion(Mapa *mapa, Entidad *pantalla);

};


#endif //FINAL_FIGHT_NIVELCLIENTE_H
