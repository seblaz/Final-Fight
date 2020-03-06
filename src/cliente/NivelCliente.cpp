//
// Created by sebas on 8/10/19.
//

#include "NivelCliente.h"
#include "../servicios/Locator.h"
#include "../graficos/Grafico.h"
#include "../modelo/serializables/Nivel.h"
#include "../graficos/GraficoDeEscenario.h"
#include "Animador.h"
#include "AnimadorElemento.h"
#include "../graficos/GraficoDeTransicion.h"
#include "../graficos/GraficoArma.h"
#include "../modelo/serializables/Elemento.h"
#include "../modelo/serializables/NumeroJugador.h"
#include "../graficos/GraficoJugador.h"
#include "../graficos/FabricaDeAnimacionesCliente.h"
#include "ReproductorSonidoPersonaje.h"
#include "../modelo/serializables/Arma.h"


void
NivelCliente::generarJugador (Entidad * jugador)
{
  Locator::logger ()->log (INFO, "Se genera jugador.");

  auto *personaje = jugador->getEstado < Personaje > ("personaje");
  auto *numeroJugador =
    jugador->getEstado < NumeroJugador > ("numeroJugador");
  Locator::logger ()->log (INFO,
			   "Se obtuvo personaje." +
			   Personaje::PersonajeACadena (personaje->
							getPersonaje ()));
  Locator::logger ()->log (INFO,
			   "Se obtuvo jugador numero" +
			   to_string (numeroJugador->numeroJugador));

  auto *spriteIndicador =
    Locator::fabricaDeSprites ()->
    getSpriteConfigPath ("/sprites/indicadores/jugador" +
			 to_string (numeroJugador->numeroJugador) + "/src");
  auto *animacionIndicador =
    FabricaDeAnimacionesCliente ("/animaciones").getAnimacion ("/indicador");

  jugador->agregarEstado ("spriteIndicador", spriteIndicador);
  jugador->agregarEstado ("animacionIndicador", animacionIndicador);

  string nombrePersonaje =
    Personaje::PersonajeACadena (personaje->getPersonaje ());
  auto *fabricaDeAnimaciones =
    new FabricaDeAnimacionesCliente ("/animaciones/" + nombrePersonaje);
  auto *reproductorSonidoPersonaje = new ReproductorSonidoPersonaje (jugador,
								     "/sonidos/personaje/"
								     +
								     nombrePersonaje);

  auto *animacion = fabricaDeAnimaciones->getAnimacion ("/reposando");
  auto *spriteJugador =
    Locator::fabricaDeSprites ()->
    getSpriteConfigPath ("/sprites/personajes/" + nombrePersonaje +
			 "/punios/src");
  auto *grafico = new GraficoJugador (jugador);
  auto *animador = new Animador (jugador);

  jugador->agregarEstado ("sprite", spriteJugador);
  jugador->agregarEstado ("animacion", animacion);
  jugador->agregarEstado ("fabrica de animaciones", fabricaDeAnimaciones);
  jugador->agregarComportamiento ("grafico", grafico);
  jugador->agregarComportamiento ("animador", animador);
  jugador->agregarComportamiento ("reproductor", reproductorSonidoPersonaje);

  auto *spriteVida =
    Locator::fabricaDeSprites ()->
    getSpriteConfigPath ("/sprites/personajes/" + nombrePersonaje +
			 "/vida/src");

  auto *spriteVidaActual =
    Locator::fabricaDeSprites ()->getSpriteConfigPath
    ("/sprites/indicadores/vidaActual/src");

  auto *spriteCantidadDeVidas =
    Locator::fabricaDeSprites ()->getSpriteConfigPath
    ("/sprites/indicadores/corazon/src");

  jugador->agregarEstado ("sprite vida", spriteVida);
  jugador->agregarEstado ("sprite vida actual", spriteVidaActual);
  jugador->agregarEstado ("sprite cantidad de vidas", spriteCantidadDeVidas);
}

void
NivelCliente::generarEscenario (Entidad * escenario)
{
  Configuracion *config = Locator::configuracion ();

  auto *nivelEstado = escenario->getEstado < Nivel > ("nivel");
  string nivel = nivelEstado->nivel ();
  Locator::logger ()->log (DEBUG, "Se genera escenario para " + nivel);

  int anchoNivel =
    config->getIntValue ("/niveles/" + nivel + "/escenario/ancho");
  int cantidadDeCapas =
    config->getIntValue ("/niveles/" + nivel +
			 "/escenario/sprite/capas/cantidad");

  Locator::logger ()->log (DEBUG,
			   "Se cargo ancho para escenario: " +
			   to_string (anchoNivel));
  Locator::logger ()->log (DEBUG,
			   "Se cargo cantidad de capas para escenario: " +
			   to_string (cantidadDeCapas));

  auto *sprite =
    Locator::fabricaDeSprites ()->getSpriteConfigPath ("/niveles/" + nivel +
						       "/escenario/sprite/src");

  vector < SDL_Texture * >sprites (cantidadDeCapas);
  vector < SDL_Rect > posicionesSprite (cantidadDeCapas);
  vector < float >distanciasAlFondo (cantidadDeCapas);

  for (int i = 0; i < cantidadDeCapas; i++)
    {
      int x =
	config->getIntValue ("/niveles/" + nivel +
			     "/escenario/sprite/capas/capa" + to_string (i) +
			     "/x");
      int y =
	config->getIntValue ("/niveles/" + nivel +
			     "/escenario/sprite/capas/capa" + to_string (i) +
			     "/y");
      int alto =
	config->getIntValue ("/niveles/" + nivel +
			     "/escenario/sprite/capas/capa" + to_string (i) +
			     "/alto");
      float distanciaAlFondo =
	config->getFloatValue ("/niveles/" + nivel +
			       "/escenario/sprite/capas/capa" +
			       to_string (i) + "/distanciaAlFondo");

      Locator::logger ()->log (DEBUG,
			       "Se obtiene eje x para capa " + to_string (i +
									  1) +
			       ": " + to_string (x));
      Locator::logger ()->log (DEBUG,
			       "Se obtiene eje y para capa " + to_string (i +
									  1) +
			       ": " + to_string (y));
      Locator::logger ()->log (DEBUG,
			       "Se obtiene alto para capa " + to_string (i +
									 1) +
			       ": " + to_string (alto));
      Locator::logger ()->log (DEBUG,
			       "Se obtiene distancia al fondo para capa " +
			       to_string (i + 1) + ": " +
			       to_string (distanciaAlFondo));

      sprites[i] = sprite->getTexture ();
      posicionesSprite[i] = { x, y, 0, alto };
      distanciasAlFondo[i] = distanciaAlFondo;
    }

  float escalaHorizontal = (float) anchoNivel / (float) sprite->ancho ();
  auto *grafico =
    new GraficoDeEscenario (escenario, sprites, posicionesSprite,
			    distanciasAlFondo, escalaHorizontal);

  escenario->agregarEstado ("sprite", sprite);
  escenario->agregarComportamiento ("grafico", grafico);

}

void
NivelCliente::generarTransicion (Entidad * transicion)
{
  Locator::logger ()->log (DEBUG, "Se genera transicion");

  auto *grafico = new GraficoDeTransicion (transicion);

  transicion->agregarComportamiento ("grafico", grafico);
}

void
NivelCliente::generarEnemigo (Entidad * enemigo)
{
  Locator::logger ()->log (INFO, "Se genera enemigo");

  auto *personaje = enemigo->getEstado < Personaje > ("personaje");

  string nombrePersonaje =
    Personaje::PersonajeACadena (personaje->getPersonaje ());
  auto *spriteEnemigo =
    Locator::fabricaDeSprites ()->
    getSpriteConfigPath ("/sprites/personajes/" + nombrePersonaje +
			 "/punios/src");
  auto *fabricaDeEnemigo =
    new FabricaDeAnimacionesCliente ("/animaciones/" + nombrePersonaje);
  auto *graficoDeEnemigo = new Grafico (enemigo);
  auto *animacion = fabricaDeEnemigo->getAnimacion (REPOSANDO);
  auto *animador = new Animador (enemigo);

  enemigo->agregarEstado ("sprite", spriteEnemigo);
  enemigo->agregarEstado ("fabrica de animaciones", fabricaDeEnemigo);
  enemigo->agregarEstado ("animacion", animacion);
  enemigo->agregarComportamiento ("grafico", graficoDeEnemigo);
  enemigo->agregarComportamiento ("animador", animador);

  auto *reproductorSonidoPersonaje = new ReproductorSonidoPersonaje (enemigo,
								     "/sonidos/enemigo/"
								     +
								     nombrePersonaje);
  enemigo->agregarComportamiento ("reproductor", reproductorSonidoPersonaje);

}

void
NivelCliente::generarElemento (Entidad * entidad)
{
  Configuracion *config = Locator::configuracion ();
  string tipoElemento =
    Elemento::ElementoACadena (entidad->getEstado < Elemento >
			       ("elemento")->getElemento ());

  auto *fabrica =
    new FabricaDeAnimacionesCliente ("/animaciones/objetos/" + tipoElemento);
  AnimacionCliente *animacion = fabrica->getAnimacion ("/sano");

  string srcSprite =
    config->getValue ("/sprites/elementos/" + tipoElemento + "/sprite/src");
  auto *sprite = Locator::fabricaDeSprites ()->getSpriteBySrc (srcSprite);
  auto *grafico = new Grafico (entidad);
  auto *animador = new AnimadorElemento (entidad);

  entidad->agregarEstado ("sprite", sprite);
  entidad->agregarEstado ("fabrica de animaciones", fabrica);
  entidad->agregarEstado ("animacion", animacion);
  entidad->agregarComportamiento ("grafico", grafico);
  entidad->agregarComportamiento ("animador", animador);

}

void
NivelCliente::generarArma (Entidad * arma)
{
  Configuracion *config = Locator::configuracion ();
  string tipoArma =
    Arma::armaACadena (arma->getEstado < Arma > ("arma")->getArma ());

  string srcSprite =
    config->getValue ("/sprites/armas/" + tipoArma + "/sprite/src");
  AnimacionCliente *animacion =
    FabricaDeAnimacionesCliente ("/animaciones/objetos").getAnimacion ("/" +
								       tipoArma);

  auto *sprite = Locator::fabricaDeSprites ()->getSpriteBySrc (srcSprite);
  auto *grafico = new GraficoArma (arma);

  arma->agregarEstado ("sprite", sprite);
  arma->agregarEstado ("animacion", animacion);
  arma->agregarComportamiento ("grafico", grafico);
}
