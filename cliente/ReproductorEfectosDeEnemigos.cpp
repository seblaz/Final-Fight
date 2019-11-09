//
// Created by poncio on 23/9/19.
//

#include "ReproductorEfectosDeEnemigos.h"
#include "../estados/Caminando.h"
#include "../modelo/serializables/EstadoDePersonaje.h"
#include "../modelo/serializables/NumeroJugador.h"

void ReproductorEfectosDeEnemigos::actualizar(Entidad *entidad) {
    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado de personaje");

    int canalAReproducir = 6;
    switch (estado->getEstado()){
        case GOLPEANDO:
        {
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/enemigos/poison/patada.wav")->getChunk();
            if (Mix_Playing(canalAReproducir)==0){
                Mix_PlayChannel( canalAReproducir, chunk, 0 );
            }
        }

            break;
    }
}