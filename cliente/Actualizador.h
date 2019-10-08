//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADOR_H
#define FINAL_FIGHT_ACTUALIZADOR_H


#include "../modelo/Mapa.h"

using namespace std;

class Actualizador {

private:
    Mapa *mapa;
    bool inicio = false;

public:
    explicit Actualizador(Mapa *mapa);
    void actualizarEntidades(stringstream &s);

};


#endif //FINAL_FIGHT_ACTUALIZADOR_H
