//
// Created by poncio on 23/9/19.
//

#include <SDL2/SDL_mixer.h>
#include "ReproductorEfectosDePersonaje.h"
#include "../estados/Caminando.h"
#include "../modelo/EstadoDePersonaje.h"

void ReproductorEfectosDePersonaje::actualizar(Entidad *entidad) {
    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado de personaje");
    switch (estado->getEstado()){
        case CAMINANDO:
            break;
        case SALTANDO:
        {
            Locator::logger()->log(DEBUG,"Se reproduce saltando");
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/saltolargo.wav")->getChunk();
            if (Mix_Playing(2)==0){
                Mix_PlayChannel( 2, chunk, 0 );
            }
        }
            break;
        case REPOSANDO:
            break;
        case GOLPEANDO:{
            Locator::logger()->log(DEBUG,"Se reproduce golpeando");
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/golpe.wav")->getChunk();
            if (Mix_Playing(2)==0){
                Mix_PlayChannel( 2, chunk, 0 );
            };
        }
            break;
        case AGACHADO:
            break;
        case PATEANDO:{
            Locator::logger()->log(DEBUG,"Se reproduce saltando con patada");
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/saltopatada.wav")->getChunk();
            if (Mix_Playing(2)==0){
                Mix_PlayChannel( 2, chunk, 0 );
            }
        }
            break;
        case SALTANDO_CON_MOVIMIENTO:
        {
            Locator::logger()->log(DEBUG,"Se reproduce saltando");
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/saltocorto.wav")->getChunk();
            if (Mix_Playing(2)==0){
                Mix_PlayChannel( 2, chunk, 0 );
            }
        }
            break;
    }
}