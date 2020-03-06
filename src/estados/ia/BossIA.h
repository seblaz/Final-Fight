//
// Created by franco on 17/11/19.
//

#ifndef FINAL_FIGHT_BOSSIA_H
#define FINAL_FIGHT_BOSSIA_H


#include "../../modelo/Entidad.h"
#include "../../modelo/Jugadores.h"
#include "../../eventos/Eventos.h"

class BossIA : public Comportamiento{

    private:
        Jugadores *jugadores;
        int ciclo = 0;

    public:
        explicit BossIA(Entidad *entidad, Jugadores *jugadores);

        void actualizar() override;
    };

class EventoBossIA : public EventoAProcesar {

    public:
        Jugadores *jugadores;
        Entidad *entidad;
        int ciclo = 0;

    public:
        explicit EventoBossIA(Jugadores* jugadores, Entidad *entidad, int ciclo);
        void resolver() override;



};


#endif //FINAL_FIGHT_BOSSIA_H
