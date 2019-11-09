//
// Created by poncio on 23/9/19.
//

#include "ReproductorEfectosDePersonaje.h"
#include "../estados/Caminando.h"
#include "../modelo/serializables/EstadoDePersonaje.h"
#include "../modelo/serializables/NumeroJugador.h"

void ReproductorEfectosDePersonaje::actualizar(Entidad *entidad) {
    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado de personaje");
    auto *numeroJugador = entidad->getEstado<NumeroJugador>("numeroJugador");
    int canalAReproducir = numeroJugador->numeroJugador;
    switch (estado->getEstado()){
        case SALTANDO:
        {
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/saltolargo.wav")->getChunk();
            if (Mix_Playing(canalAReproducir)==0){
                Mix_PlayChannel( canalAReproducir, chunk, 0 );
            }
        }
            break;
        case GOLPEANDO:{

            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/golpe.wav")->getChunk();
            if (Mix_Playing(canalAReproducir)==0){
                Mix_PlayChannel( canalAReproducir, chunk, 0 );
            };
        }
            break;
        case PATEANDO:{
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/saltopatada.wav")->getChunk();
                 if (Mix_Playing(canalAReproducir)==0){
                Mix_PlayChannel( canalAReproducir, chunk, 0 );
            }
        }
            break;
        case SALTANDO_CON_MOVIMIENTO:
        {
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/saltocorto.wav")->getChunk();
            if (Mix_Playing(canalAReproducir)==0){
                Mix_PlayChannel( canalAReproducir, chunk, 0 );
            }
        }
            break;
    }
}