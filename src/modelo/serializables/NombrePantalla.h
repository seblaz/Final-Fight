//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_NOMBREPANTALLA_H
#define FINAL_FIGHT_NOMBREPANTALLA_H


#include "Serializable.h"

typedef string IdEtapa;

class NombrePantalla:public Serializable
{

private:
  IdEtapa id;

public:
  NombrePantalla ();
  explicit NombrePantalla (IdEtapa id);
  void setId (IdEtapa id);
  IdEtapa getId ();
  void serializar (ostream & stream) override;
  void deserializar (istream & stream) override;

};


#endif //FINAL_FIGHT_NOMBREPANTALLA_H
