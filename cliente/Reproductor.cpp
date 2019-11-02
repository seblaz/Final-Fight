//
// Created by poncio on 23/9/19.
//

#include <SDL2/SDL_mixer.h>
#include "Reproductor.h"
#include "../estados/Caminando.h"
#include "../modelo/EstadoDePersonaje.h"

void Reproductor::actualizar(Entidad *entidad) {

    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado de personaje");

    //Mix_Chunk * gScratch = Mix_LoadWAV( "/home/felipe/Documentos/Final-Fight/assets/sonidos/attack.wav" );



    //(auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
    switch (estado->getEstado()){
        case CAMINANDO:
            break;
        case SALTANDO:
            break;
        case REPOSANDO:
            break;
        case GOLPEANDO:{
            Locator::logger()->log(DEBUG,"Se reproduce golpenaod");
            Mix_Chunk *chunk = Locator::fabricaDeSonidos()->getSoundBySrc("/home/felipe/Documentos/Final-Fight/assets/sonidos/attack.wav")->getChunk();
            Mix_PlayChannel( 1, chunk, 0 );
        }
            break;
        case AGACHADO:
            break;
        case PATEANDO:
            break;
        case SALTANDO_CON_MOVIMIENTO:
            break;
    }
}