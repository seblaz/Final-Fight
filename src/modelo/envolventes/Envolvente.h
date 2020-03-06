//
// Created by sebas on 11/11/19.
//

#ifndef FINAL_FIGHT_ENVOLVENTE_H
#define FINAL_FIGHT_ENVOLVENTE_H


#include "../Entidad.h"
#include "../serializables/Posicion.h"

class Envolvente:public Estado
{

public:
  int ancho;
  int profundidad;
  Posicion *posicion;

  explicit Envolvente (Posicion * posicion, int ancho, int profundidad);

};


#endif //FINAL_FIGHT_ENVOLVENTE_H
