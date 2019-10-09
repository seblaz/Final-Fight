//
// Created by sebas on 9/10/19.
//

#ifndef FINAL_FIGHT_EVENTOPERSONAJE_H
#define FINAL_FIGHT_EVENTOPERSONAJE_H


#include "Eventos.h"

class Reposar : public EventoAProcesar {

private:
    Mapa *mapa;
    
public:
    explicit Reposar(Mapa *mapa);
    void resolver() override;
};


class Saltar : public EventoAProcesar {

private:
    Mapa *mapa;
    
public:
    explicit Saltar(Mapa *mapa);
    void resolver() override;
};

class Golpear : public EventoAProcesar {

private:
    Mapa *mapa;
    
public:
    explicit Golpear(Mapa *mapa);
    void resolver() override;
};

#endif //FINAL_FIGHT_EVENTOPERSONAJE_H
