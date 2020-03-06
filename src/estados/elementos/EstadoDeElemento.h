//
// Created by sebas on 16/11/19.
//

#ifndef FINAL_FIGHT_ESTADODEELEMENTO_H
#define FINAL_FIGHT_ESTADODEELEMENTO_H

#include "../EstadoDeColisionable.h"

class EstadoDeElemento:public EstadoDeColisionable
{

public:
  using EstadoDeColisionable::EstadoDeColisionable;
  void recibirGolpeDe (Entidad * jugador) override = 0;

};

#endif //FINAL_FIGHT_ESTADODEELEMENTO_H
