//
// Created by franco on 29/10/19.
//

#ifndef FINAL_FIGHT_BUSCARJUGADORES_H
#define FINAL_FIGHT_BUSCARJUGADORES_H


#include "../../modelo/Entidad.h"
#include "../../modelo/Jugadores.h"
#include "../personajes/EstadoDePersonajeServidor.h"

class BuscarJugadores : public Comportamiento {

private:
    Jugadores *jugadores;
    int ciclo = 0;

public:
    explicit BuscarJugadores(Entidad *entidad, Jugadores *jugadores);

    void actualizar() override;
};

class EventoBuscarJugadores : public EventoAProcesar {

public:
    Jugadores *jugadores;
    Entidad *entidad;
    int ciclo = 0;

public:
    explicit EventoBuscarJugadores(Jugadores* jugadores, Entidad *entidad, int ciclo);
    void resolver() override;
    
};

#endif //FINAL_FIGHT_BUSCARJUGADORES_H
