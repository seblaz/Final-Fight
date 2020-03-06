//
// Created by sebas on 20/10/19.
//

#ifndef FINAL_FIGHT_FABRICADEANIMACIONESSERVIDOR_H
#define FINAL_FIGHT_FABRICADEANIMACIONESSERVIDOR_H


#include "AnimacionServidor.h"
#include "../modelo/serializables/Personaje.h"
#include "../modelo/serializables/EstadoDePersonaje.h"

class FabricaDeAnimacionesServidor
{

public:
  static AnimacionServidor *getAnimacion (Entidad * entidad,
					  const string & ruta);
  static AnimacionServidor *getAnimacion (Entidad * entidad,
					  enum PERSONAJE
					  personajeSeleccionado,
					  const string & estado);
  static AnimacionServidor *getAnimacion (Entidad * entidad,
					  enum PERSONAJE
					  personajeSeleccionado,
					  enum ESTADO_DE_PERSONAJE estado);

};


#endif //FINAL_FIGHT_FABRICADEANIMACIONESSERVIDOR_H
