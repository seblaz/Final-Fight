//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_NIVELSERVIDOR_H
#define FINAL_FIGHT_NIVELSERVIDOR_H


#include "../modelo/Mapa.h"
#include "../servicios/Locator.h"
#include "../modelo/serializables/Posicion.h"
#include "../modelo/serializables/Orientacion.h"
#include "../modelo/serializables/Personaje.h"
#include "../modelo/serializables/Elemento.h"
#include "../modelo/serializables/Arma.h"


class NivelServidor
{

private:
  static void generarTransicion (const string & nivel, Mapa * mapa,
				 Jugadores * posicionDeJugador);
  static void generarEnemigo (const string & nivel, Mapa * mapa,
			      Jugadores * jugadores);
  static void generarElementos (const string & nivel, Mapa * mapa,
				ELEMENTO objeto);
  static void generarArmas (const string & nivel, Mapa * mapa, ARMA tipoArma);
  static void generarJefeFinal (const string & nivel, Mapa * mapa,
				Jugadores * jugadores);

public:
  static Entidad *generarJugador (Mapa * mapa,
				  enum PERSONAJE personajeSeleccionado,
				  int numeroJugador);

  static void generarNivel (const string & nivel, Mapa * mapa);
  static Entidad *generarEscenario (const string & nivel, Mapa * mapa);
};


#endif //FINAL_FIGHT_NIVELSERVIDOR_H
