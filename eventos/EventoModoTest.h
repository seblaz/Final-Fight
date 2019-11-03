//
// Created by leo on 3/11/19.
//

#ifndef FINAL_FIGHT_EVENTOMODOTEST_H
#define FINAL_FIGHT_EVENTOMODOTEST_H


#include "Eventos.h"

class EventoModoTest : public EventoAProcesar{

protected:
    Entidad *personaje;

public:
    explicit EventoModoTest(Entidad *personaje);
    void resolver() override;
};


#endif //FINAL_FIGHT_EVENTOMODOTEST_H
