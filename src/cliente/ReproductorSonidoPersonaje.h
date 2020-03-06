//
// Created by poncio on 23/9/19.
//

#ifndef FINAL_FIGHT_REPRODUCTORSONIDOPERSONAJE_H
#define FINAL_FIGHT_REPRODUCTORSONIDOPERSONAJE_H

#include "../modelo/Entidad.h"

class ReproductorSonidoPersonaje:public Comportamiento
{

private:
  string rutaBase;

public:
  explicit ReproductorSonidoPersonaje (Entidad * entidad, string rutaBase);
  void actualizar () override;
};

#endif // FINAL_FIGHT_REPRODUCTORSONIDOPERSONAJE_H
