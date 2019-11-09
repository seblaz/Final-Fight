//
// Created by franco on 31/10/19.
//

#ifndef FINAL_FIGHT_COLISIONABLES_H
#define FINAL_FIGHT_COLISIONABLES_H


#include "Entidad.h"
#include "Jugadores.h"

class Colisionables : public Estado {

private:

    vector<Entidad *> colisionables;
    vector<Entidad *> jugadores;
    vector<Entidad *> enemigos;
    int limiteEnProfundidad = 0;
    int limiteFrontal = 0;
    int i = 0;

public:
    explicit Colisionables() = default;
    void add(Entidad *);
    void addLimitesDeEscenario(int profundidad, int frente);

    void calcularPosiblesColisiones();
    void calcularAtaques();
};


#endif //FINAL_FIGHT_COLISIONABLES_H
