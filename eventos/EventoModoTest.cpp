//
// Created by leo on 3/11/19.
//

#include "EventoModoTest.h"
#include "../modelo/serializables/Energia.h"

EventoModoTest::EventoModoTest(Entidad *personaje) : personaje(personaje) {}

void EventoModoTest::resolver() {
    personaje->getEstado<Energia>("energia")->cambiarModoTest();
}