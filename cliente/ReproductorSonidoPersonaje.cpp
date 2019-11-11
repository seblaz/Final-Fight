//
// Created by poncio on 23/9/19.
//

#include "ReproductorSonidoPersonaje.h"
#include "../estados/Caminando.h"
#include "../modelo/serializables/NumeroJugador.h"

ReproductorSonidoPersonaje::ReproductorSonidoPersonaje(string rutaBase) : rutaBase(std::move(rutaBase)) {}

void ReproductorSonidoPersonaje::actualizar(Entidad *entidad) {

    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado de personaje");
    auto *numeroJugador = entidad->getEstado<NumeroJugador>("numeroJugador");
    int canalAReproducir;

    string pathSonidoABuscar = rutaBase + estado->estadoACadena(estado->getEstado()) + "/src";

    if (numeroJugador == NULL) {
        canalAReproducir = 6;
    } else {
        canalAReproducir = numeroJugador->numeroJugador;
    }

    Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundConfigPath(pathSonidoABuscar)->getChunk();

    if (chunk != NULL) {
        if (Mix_Playing(canalAReproducir) == 0) {
            Mix_PlayChannel(canalAReproducir, chunk, 0);
        }
    }


}