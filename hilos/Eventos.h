//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_EVENTOS_H
#define FINAL_FIGHT_EVENTOS_H

//#include <queue>
#include <mutex>
#include "Evento.h"
#include "queue.h"

using namespace std;

class Eventos {

private:
    blocking_queue<Evento*> cola;


public:
    void push(Evento *elem) {
        cola.push(elem);
    }

    Evento *pop() {
        return cola.pop();
    }
};


#endif //FINAL_FIGHT_EVENTOS_H
