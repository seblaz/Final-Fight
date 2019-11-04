//
// Created by franco on 29/10/19.
//

#ifndef FINAL_FIGHT_BUSCARJUGADORES_H
#define FINAL_FIGHT_BUSCARJUGADORES_H


#include "../../modelo/Entidad.h"
#include "../../modelo/Jugadores.h"
#include "../EstadoDePersonajeServidor.h"

class BuscarJugadores : public Comportamiento {

private:
    Jugadores *jugadores;

public:
    explicit BuscarJugadores(Jugadores* jugadores);

    void actualizar(Entidad *) override;
};

class EventoBuscarJugadores : public EventoAProcesar {

public:
    Jugadores *jugadores;
    Entidad *entidad;

public:
    explicit EventoBuscarJugadores(Jugadores* jugadores, Entidad *entidad);
    void resolver() override;
    
};

#endif //FINAL_FIGHT_BUSCARJUGADORES_H
