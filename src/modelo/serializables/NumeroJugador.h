//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_NUMEROJUGADOR_H
#define FINAL_FIGHT_NUMEROJUGADOR_H


#include "../Entidad.h"

/**
 * Modela una direccion. A nivel de implementación es un vector unitario.
 */
class NumeroJugador:public Estado
{
public:
  int numeroJugador;
    NumeroJugador ();
  explicit NumeroJugador (int numeroJugador);

  void serializar (ostream & stream) override;
  void deserializar (istream & stream) override;
};



#endif //FINAL_FIGHT_NUMEROJUGADOR_H
