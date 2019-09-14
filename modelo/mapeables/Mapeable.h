//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPEABLE_H
#define FINAL_FIGHT_MAPEABLE_H


#include "../../graficos/Grafico.h"

using namespace std;

class Comportamiento;
class Fisica;

class Mapeable {

private:
    Fisica *fisica;
    Grafico *grafico;
    Comportamiento *comportamiento;

public:
    Mapeable(Fisica *fisica, Grafico *grafico, Comportamiento *comportamiento);
    virtual void actualizar();
};

#include "../../fisica/Fisica.h"
#include "../../comportamiento/Comportamiento.h"


#endif //FINAL_FIGHT_MAPEABLE_H
