//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADORJUEGO_H
#define FINAL_FIGHT_ACTUALIZADORJUEGO_H


#include "../../modelo/Mapa.h"
#include "../../eventos/Eventos.h"

class ActualizadorJuego {

private:
    bool fin_ = false;
    Mapa *mapa;
    EventosAProcesar *eventos;

public:
    explicit ActualizadorJuego(Mapa *mapa, EventosAProcesar *eventos);
    void interpretarComando(stringstream &s);
    bool fin();

};


#endif //FINAL_FIGHT_ACTUALIZADORJUEGO_H
