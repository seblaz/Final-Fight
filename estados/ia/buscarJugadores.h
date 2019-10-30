//
// Created by franco on 29/10/19.
//

#ifndef FINAL_FIGHT_BUSCARJUGADORES_H
#define FINAL_FIGHT_BUSCARJUGADORES_H


#include "../../modelo/Entidad.h"
#include "../../modelo/Jugadores.h"
#include "../EstadoDePersonajeServidor.h"

class buscarJugadores : public Comportamiento {

private:
    Jugadores *jugadores;

public:
    explicit buscarJugadores(Jugadores* jugadores);

    void actualizar(Entidad *) override;
};


#endif //FINAL_FIGHT_BUSCARJUGADORES_H
