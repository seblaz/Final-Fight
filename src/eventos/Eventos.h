//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_EVENTOS_H
#define FINAL_FIGHT_EVENTOS_H

#include <string>
#include <utility>
#include <cstdarg>
#include "../modelo/Mapa.h"
#include "queue.h"

using namespace std;

class EventoAProcesar
{

public:
  virtual ~ EventoAProcesar () = default;
  virtual void resolver () = 0;

};

class EventosAProcesar
{

private:
  blocking_queue < EventoAProcesar * >cola;

public:
  EventosAProcesar ();
  void push (EventoAProcesar * elem)
  {
    cola.push (elem);
  }

  EventoAProcesar *pop ()
  {
    return cola.pop ();
  }
};

#endif //FINAL_FIGHT_EVENTOS_H
