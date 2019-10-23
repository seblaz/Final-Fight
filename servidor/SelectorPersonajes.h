//
// Created by sebas on 13/10/19.
//

#ifndef FINAL_FIGHT_SELECTORPERSONAJES_H
#define FINAL_FIGHT_SELECTORPERSONAJES_H

#include <mutex>
#include "../usuario/Usuario.h"

using namespace std;

class SelectorPersonajes {

private:
    unordered_map<string, Usuario*> usuarios;
    int jugadoresMax;
    mutex m_mutex;

public:
    explicit SelectorPersonajes(int jugadores);
    void confirmar(Usuario *usuario);
    void quitar(Usuario *usuario);
    bool puedoComenzar();

};


#endif //FINAL_FIGHT_SELECTORPERSONAJES_H
