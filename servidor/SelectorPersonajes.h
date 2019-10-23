//
// Created by sebas on 13/10/19.
//

#ifndef FINAL_FIGHT_SELECTORPERSONAJES_H
#define FINAL_FIGHT_SELECTORPERSONAJES_H

#include <mutex>

using namespace std;

class SelectorPersonajes {

private:
    int jugadores;
    mutex m_mutex;

public:
    explicit SelectorPersonajes(int jugadores);
    void confirmar();
    bool puedoComenzar();

};


#endif //FINAL_FIGHT_SELECTORPERSONAJES_H
