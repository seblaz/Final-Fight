//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADORJUEGO_H
#define FINAL_FIGHT_ACTUALIZADORJUEGO_H


#include "../../modelo/Mapa.h"
#include "../../eventos/Eventos.h"
#include "../../usuario/Usuario.h"

class ActualizadorJuego {

private:
    bool fin_ = false;
    Mapa *mapa;
    EventosAProcesar *eventos;
    Entidad *jugador;

public:
    explicit ActualizadorJuego(Mapa *mapa, EventosAProcesar *eventos, Entidad *jugador);
    void interpretarStream(stringstream &s);
    bool fin();
    void actualizarJuego(Usuario *pUsuario);

};


class SetActividadJugador : public EventoAProcesar {

private:
    Entidad *jugador;
    bool activo;

public:
    explicit SetActividadJugador(Entidad *jugador, bool activo);
    void resolver() override;

};

#endif //FINAL_FIGHT_ACTUALIZADORJUEGO_H
