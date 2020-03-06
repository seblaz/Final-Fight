//
// Created by poncio on 23/9/19.
//

#include "ReproductorSonidoPersonaje.h"
#include "../estados/personajes/Caminando.h"
#include "../modelo/serializables/NumeroJugador.h"
#include "../modelo/serializables/Energia.h"

ReproductorSonidoPersonaje::ReproductorSonidoPersonaje (Entidad * entidad, string rutaBase):
Comportamiento (entidad),
rutaBase (std::move (rutaBase))
{
}

void
ReproductorSonidoPersonaje::actualizar ()
{

  auto *estado =
    entidad->getEstado < EstadoDePersonaje > ("estado de personaje");
  auto *numeroJugador =
    entidad->getEstado < NumeroJugador > ("numeroJugador");
  auto *energia = entidad->getEstado < Energia > ("energia");

  string pathSonidoABuscar =
    rutaBase + "/" + EstadoDePersonaje::estadoACadena (estado->getEstado ()) +
    "/src";

  int canalAReproducir = numeroJugador ? numeroJugador->numeroJugador : 6;

  Mix_Chunk *chunk =
    Locator::fabricaDeSonidos ()->getSoundConfigPath (pathSonidoABuscar)->
    getChunk ();

  if (chunk && Mix_Playing (canalAReproducir) == 0
      && energia->getVidas () >= 0)
    Mix_PlayChannel (canalAReproducir, chunk, 0);
}
