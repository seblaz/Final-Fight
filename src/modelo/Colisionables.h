//
// Created by franco on 31/10/19.
//

#ifndef FINAL_FIGHT_COLISIONABLES_H
#define FINAL_FIGHT_COLISIONABLES_H


#include "Entidad.h"
#include "Jugadores.h"

class Colisionables:public Estado
{

private:

  int limiteEnProfundidad = 0;
  int limiteFrontal = 0;
  int i = 0;
  void calcularPosiblesColisiones ();
  void calcularArmasAlcanzables ();

  void calcularAtaquesEntre (vector < Entidad * >&atacantes,
			     vector < Entidad * >&defensores);

public:
    explicit Colisionables () = default;
  void addLimitesDeEscenario (int profundidad, int frente);
  void calcularInteracciones ();
};


#endif //FINAL_FIGHT_COLISIONABLES_H
