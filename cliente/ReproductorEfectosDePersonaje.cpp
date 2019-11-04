//
// Created by poncio on 23/9/19.
//

#include <SDL2/SDL_mixer.h>
#include "ReproductorEfectosDePersonaje.h"
#include "../estados/Caminando.h"
#include "../modelo/serializables/EstadoDePersonaje.h"

void ReproductorEfectosDePersonaje::actualizar(Entidad *entidad) {
    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado de personaje");
    switch (estado->getEstado()){
        case CAMINANDO:
        {
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/paso.wav")->getChunk();
            if (Mix_Playing(-1)==0){
                Mix_PlayChannel( -1, chunk, 0 );
            }
        }
        case SALTANDO:
        {

            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/saltolargo.wav")->getChunk();
            if (Mix_Playing(-1)==0){
                Mix_PlayChannel( -1, chunk, 0 );
            }
        }
            break;
        case GOLPEANDO:{

            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/golpe.wav")->getChunk();
            if (Mix_Playing(-1)==0){
                Mix_PlayChannel( -1, chunk, 0 );
            };
        }
            break;
        case PATEANDO:{
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/saltopatada.wav")->getChunk();
            if (Mix_Playing(-1)==0){
                Mix_PlayChannel( -1, chunk, 0 );
            }
        }
            break;
        case SALTANDO_CON_MOVIMIENTO:
        {
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("assets/sonidos/saltocorto.wav")->getChunk();
            if (Mix_Playing(-1)==0){
                Mix_PlayChannel( -1, chunk, 0 );
            }
        }
            break;
    }
}