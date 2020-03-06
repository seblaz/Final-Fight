//
// Created by franco on 12/10/19.
//

#ifndef FINAL_FIGHT_FISICADETRANSICION_H
#define FINAL_FIGHT_FISICADETRANSICION_H

#include "../modelo/Entidad.h"

class FisicaDeTransicion:public Comportamiento
{

private:
  int anchoDeEscenario;
  int framesPorTransicionInicial;
  int framesFaltantesPorTranscionInicial;
  int margenTransicionFinal;

public:
    explicit FisicaDeTransicion (Entidad * entidad, int anchoDeEscenario);
  void actualizar () override;
};

#endif //FINAL_FIGHT_FISICADETRANSICION_H
