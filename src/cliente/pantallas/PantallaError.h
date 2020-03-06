//
// Created by sebas on 2/11/19.
//

#ifndef FINAL_FIGHT_PANTALLAERROR_H
#define FINAL_FIGHT_PANTALLAERROR_H


#include "Pantalla.h"

using namespace std;

class PantallaError:public Pantalla
{

private:
  string configPath;

public:
  explicit PantallaError (IdPantalla id, string configPath);
  void enviar (SDL_Event * e) override
  {
  };
  void recibir (stringstream & s) override
  {
  };
  void interpretarModelo (stringstream & s) override
  {
  };
  void graficar (SDL_Renderer * renderer) override;
  void iniciar () override;

};


#endif //FINAL_FIGHT_PANTALLAERROR_H
