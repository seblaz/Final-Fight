//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_SALTANDO_H
#define FINAL_FIGHT_SALTANDO_H

#include "EstadoDePersonajeServidor.h"
#include "../../modelo/serializables/Arma.h"

class Saltando:public EstadoDePersonajeServidor
{

private:
  Arma * armaPrevia;
  bool pateando = false;
  float frames = 1;
  const float velocidadInicial = 25;
  const float aceleracion = -1;

public:
    explicit Saltando (Entidad * entidad);
  void actualizar () override;
  void darGolpe () override;
  void saltar () override
  {
  };
  void caminar (bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) override
  {
  };
  void agachar () override
  {
  };
  void reposar () override
  {
  };
  void recibirGolpeDe (Entidad *) override
  {
  }
};


#endif //FINAL_FIGHT_SALTANDO_H
