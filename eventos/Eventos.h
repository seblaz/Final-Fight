//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_EVENTOS_H
#define FINAL_FIGHT_EVENTOS_H

#include <string>
#include <utility>
#include <cstdarg>
#include "../modelo/Mapa.h"
#include "queue.h"

using namespace std;

class EventoAProcesar {

private:
    string msj_;

public:
    explicit EventoAProcesar(string msg = "");
    virtual void resolver(Mapa&) {};
    string msj();

};

class EventosAProcesar {

private:
    blocking_queue<EventoAProcesar*> cola;

public:
    void push(EventoAProcesar *elem) {
        cola.push(elem);
    }

    EventoAProcesar *pop() {
        return cola.pop();
    }
};

class EventoATransmitir {

private:
    string msj_;

public:
    explicit EventoATransmitir(string msg = "");
    string msj();

};

class EventosATransmitir {

private:
    blocking_queue<EventoATransmitir*> cola;

public:
    void push(EventoATransmitir *elem) {
        cola.push(elem);
    }

    EventoATransmitir *pop() {
        return cola.pop();
    }
};

#endif //FINAL_FIGHT_EVENTOS_H
