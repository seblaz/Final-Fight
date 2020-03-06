//
// Created by franco on 20/10/19.
//

#ifndef FINAL_FIGHT_INDICESPRITE_H
#define FINAL_FIGHT_INDICESPRITE_H

#include "../Entidad.h"

class IndiceSprite:public Estado
{

private:
  int indice = 0;

public:
    IndiceSprite () = default;
  void serializar (ostream & stream) override;
  void deserializar (istream & stream) override;

  void setIndice (int pos);
  int getIndice ();
};


#endif //FINAL_FIGHT_INDICESPRITE_H
