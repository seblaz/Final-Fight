//
// Created by sebas on 1/11/19.
//

#ifndef FINAL_FIGHT_MANAGERPANTALLAS_H
#define FINAL_FIGHT_MANAGERPANTALLAS_H

#include <string>
#include <unordered_map>
#include "Pantalla.h"

class Pantalla;

using namespace std;

class ManagerPantallas
{

private:
  unordered_map < IdPantalla, Pantalla * >pantallas;
  Pantalla *actual = nullptr;
  mutex m;

public:
  void agregarPantalla (Pantalla * pantalla);
  void cambiarA (const IdPantalla & idPantalla);
  Pantalla *getActual ();
};


#endif //FINAL_FIGHT_MANAGERPANTALLAS_H
