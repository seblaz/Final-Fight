//
// Created by sebas on 16/11/19.
//

#ifndef FINAL_FIGHT_NOTIFICADORDEGOLPES_H
#define FINAL_FIGHT_NOTIFICADORDEGOLPES_H

#include "../../modelo/Entidad.h"
#include "../../modelo/serializables/Elemento.h"

class NotificadorDeGolpes:public Estado
{

public:
  virtual void notificarGolpeAPersonaje (Entidad * personajeGolpeado)
  {
  };
  virtual void notificarGolpeAElemento (Elemento * elementoGolpeado)
  {
  };

};

#endif //FINAL_FIGHT_NOTIFICADORDEGOLPES_H
