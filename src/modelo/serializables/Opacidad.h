//
// Created by franco on 12/10/19.
//

#ifndef FINAL_FIGHT_OPACIDAD_H
#define FINAL_FIGHT_OPACIDAD_H

#include "../Entidad.h"

class Opacidad:public Estado
{
public:
  int opacidad = 0;

  explicit Opacidad () = default;

  void setOpacidad (int opacidad);
  int getOpacidad ();

  void serializar (ostream & stream) override;
  void deserializar (istream & stream) override;

};

#endif //FINAL_FIGHT_OPACIDAD_H
