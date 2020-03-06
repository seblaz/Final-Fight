//energia
// Created by franco on 29/10/19.
//

#ifndef FINAL_FIGHT_ENERGIA_H
#define FINAL_FIGHT_ENERGIA_H


#include "Serializable.h"
#include "../Entidad.h"

class Energia:public Estado
{

private:
  int puntosDeEnergiaMaximos;
  int puntosDeEnergia;
  int vidas;
  bool modoTest = false;

public:
    Energia () = default;
  explicit Energia (int puntosDeEnergia, int vidas);
  void serializar (ostream & stream) override;
  void deserializar (istream & stream) override;

  void restarEnergia (int energiaRestada);
  bool conEnergia ();
  bool vivo ();
  bool revivir ();
  int getEnergia ();
  int getVidas ();

  void cambiarModoTest ();
  bool enModoTest ();

};


#endif //FINAL_FIGHT_ENERGIA_H
