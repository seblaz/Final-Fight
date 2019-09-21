//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPEABLE_H
#define FINAL_FIGHT_MAPEABLE_H


#include "../../graficos/Grafico.h"

class IComportamiento;
class Fisica;

class Mapeable {

private:
    Fisica *fisica_;
    Grafico *grafico_;
    IComportamiento *comportamiento_;

public:
    Mapeable(Fisica *fisica, Grafico *grafico, IComportamiento *comportamiento);
    Fisica *fisica(){ return fisica_; };
    Grafico *grafico(){ return grafico_; };
    IComportamiento *comportamiento(){ return comportamiento_; };
};

#include "../../fisica/Fisica.h"
#include "../../comportamiento/IComportamiento.h"


#endif //FINAL_FIGHT_MAPEABLE_H
