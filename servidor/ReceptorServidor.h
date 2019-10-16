//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_RECEPTORSERVIDOR_H
#define FINAL_FIGHT_RECEPTORSERVIDOR_H


#include "../eventos/Eventos.h"
#include "actualizadores/ActualizadorJuego.h"
#include "../modelo/Socket.h"
#include "../usuario/ManagerUsuarios.h"
#include "SelectorPersonajes.h"

class ReceptorServidor {

private:
    Mapa *mapa;
    Socket socket;
    ManagerUsuarios *manager;
    EventosAProcesar *eventos;
    SelectorPersonajes *selector;
    semaphore *confirmacion;

public:
    ReceptorServidor(Mapa *mapa, Socket socket, ManagerUsuarios *manager, EventosAProcesar *eventos,
                     SelectorPersonajes *selector, semaphore *confirmacion);
    void recibir();

};

class SetActividadJugador : public EventoAProcesar {

private:
    Entidad *jugador;
    bool activo;
    
public:
    explicit SetActividadJugador(Entidad *jugador, bool activo);
    void resolver() override;

};

#endif //FINAL_FIGHT_RECEPTORSERVIDOR_H
