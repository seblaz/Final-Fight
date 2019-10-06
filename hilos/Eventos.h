//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_EVENTOS_H
#define FINAL_FIGHT_EVENTOS_H

#include <queue>
#include <mutex>
#include "../servidor/Evento.h"

using namespace std;

class Eventos {

private:
    queue<Evento> cola;
    mutex m;

public:
    void push(Evento elem) {
        lock_guard<std::mutex> lock(m);
        cola.push(elem);
    }

    Evento pop() {
        lock_guard<std::mutex> lock(m);
        Evento elem = cola.front();
        cola.pop();
        return elem;
    }
};


#endif //FINAL_FIGHT_EVENTOS_H
