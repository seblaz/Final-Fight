//
// Created by sebas on 7/11/19.
//

#ifndef FINAL_FIGHT_PUNTUACIONJUGADORES_H
#define FINAL_FIGHT_PUNTUACIONJUGADORES_H


#include <unordered_map>

using namespace std;

class PuntuacionJugadores
{

private:
  unordered_map < string, int >puntuaciones;

public:
  void setPuntuacion (string jugador, int puntuacion);
    unordered_map < string, int >getPuntuaciones ();

};


#endif //FINAL_FIGHT_PUNTUACIONJUGADORES_H
