//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPEABLE_H
#define FINAL_FIGHT_MAPEABLE_H


#include "../../graficos/Grafico.h"

class Comportamiento;
class Fisica;

class Mapeable {

private:
    Fisica *fisica_;
    Grafico *grafico_;
    Comportamiento *comportamiento_;

public:
    Mapeable(Fisica *fisica, Grafico *grafico, Comportamiento *comportamiento);
    Fisica *fisica(){ return fisica_; };
    Grafico *grafico(){ return grafico_; };
    Comportamiento *comportamiento(){ return comportamiento_; };
};

#include "../../fisica/Fisica.h"
#include "../../comportamiento/Comportamiento.h"


#endif //FINAL_FIGHT_MAPEABLE_H
