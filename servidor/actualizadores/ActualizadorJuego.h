//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADORJUEGO_H
#define FINAL_FIGHT_ACTUALIZADORJUEGO_H


#include "../../modelo/Mapa.h"
#include "../../eventos/Eventos.h"
#include "Actualizador.h"

class ActualizadorJuego : public Actualizador {

private:
    bool fin_ = false;
    Mapa *mapa;
    EventosAProcesar *eventos;

public:
    explicit ActualizadorJuego(Mapa *mapa, EventosAProcesar *eventos);
    void interpretarStream(stringstream &s) override;
    bool fin() override;

};


#endif //FINAL_FIGHT_ACTUALIZADORJUEGO_H
