//
// Created by sebas on 9/10/19.
//

#ifndef FINAL_FIGHT_EVENTOPERSONAJE_H
#define FINAL_FIGHT_EVENTOPERSONAJE_H


#include "Eventos.h"

class EventoPersonaje:public EventoAProcesar
{

protected:
  Entidad * personaje;

public:
  explicit EventoPersonaje (Entidad * personaje);

};

class Reposar:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};


class Saltar:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};

class Golpear:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};

class Agachar:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};


class CaminarIzquierda:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};

class CaminarDerecha:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};

class CaminarArriba:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};

class CaminarAbajo:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};

class CaminarIzquierdaArriba:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};

class CaminarIzquierdaAbajo:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};

class CaminarDerechaArriba:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};

class CaminarDerechaAbajo:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};

class ModoTest:public EventoPersonaje
{

public:
  using EventoPersonaje::EventoPersonaje;
  void resolver () override;

};

#endif //FINAL_FIGHT_EVENTOPERSONAJE_H
