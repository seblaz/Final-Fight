//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADORSERVIDOR_H
#define FINAL_FIGHT_ACTUALIZADORSERVIDOR_H


#include "../modelo/Mapa.h"
#include "../eventos/Eventos.h"

class ActualizadorServidor {

private:
    Mapa *mapa;
    EventosAProcesar *eventos;

public:
    explicit ActualizadorServidor(Mapa *mapa, EventosAProcesar *eventos);
    void interpretarComando(stringstream &s);

};


#endif //FINAL_FIGHT_ACTUALIZADORSERVIDOR_H
