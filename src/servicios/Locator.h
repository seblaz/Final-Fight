//
// Created by sebas on 8/9/19.
// Simple implementacion de https://gameprogrammingpatterns.com/service-locator.html.
//

#ifndef FINAL_FIGHT_LOCATOR_H
#define FINAL_FIGHT_LOCATOR_H

#include <SDL_system.h>
#include <SDL_ttf.h>
#include "./Logger.h"
#include "Configuracion.h"
#include "../modelo/serializables/Posicion.h"
#include "../utils/Socket.h"
#include "../cliente/fabricas/FabricaDeSprites.h"
#include "../cliente/fabricas/FabricaDeSonidos.h"
#include "../cliente/fabricas/FabricaDeMusicas.h"
#include "../eventos/Eventos.h"
#include "../usuario/ManagerUsuarios.h"
#include "../servidor/clientes/ManagerClientes.h"
#include "../modelo/Colisionables.h"

class Locator
{

public:
  static Logger *logger ();
  static void provide (Logger * logger);

  static Configuracion *configuracion ();
  static void provide (Configuracion * configuracion);

  static Socket *socket ();
  static void provide (Socket * socket);

  static SDL_Renderer *renderer ();
  static void provide (SDL_Renderer *);

  static Posicion *posicionEscenario ();
  static void provide (Posicion * posicion);

  static FabricaDeSprites *fabricaDeSprites ();
  static void provide (FabricaDeSprites * fabricaDeSprites);

  static TTF_Font *fuente ();
  static void provide (TTF_Font * fuente);

  static EventosAProcesar *eventos ();
  static void provide (EventosAProcesar *);

  static ManagerUsuarios *usuarios ();
  static void provide (ManagerUsuarios *);

  static Mapa *mapa ();
  static void provide (Mapa *);

  static ManagerClientes *clientes ();
  static void provide (ManagerClientes *);

  static Colisionables *colisionables ();
  static void provide (Colisionables *);

  static FabricaDeSonidos *fabricaDeSonidos ();
  static void provide (FabricaDeSonidos * fabricaDeSonidos);

  static FabricaDeMusicas *fabricaDeMusicas ();
  static void provide (FabricaDeMusicas * fabricaDeMusicas);

  static void clean ();

private:
  static Socket *socket_;
  static Logger *logger_;
  static Configuracion *configuracion_;
  static SDL_Renderer *renderer_;
  static Posicion *posicion;
  static FabricaDeSprites *fabrica;
  static TTF_Font *fuente_;
  static EventosAProcesar *eventos_;
  static ManagerUsuarios *usuarios_;
  static Mapa *mapa_;
  static ManagerClientes *clientes_;
  static Colisionables *colisionables_;
  static FabricaDeSonidos *fabricaSonidos;
  static FabricaDeMusicas *fabricaMusicas;

};

#endif //FINAL_FIGHT_LOCATOR_H
