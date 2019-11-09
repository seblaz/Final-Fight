//
// Created by felipe on 2/11/19.
//


#include "Sonido.h"
#include "../servicios/Locator.h"

Sonido::Sonido(const string &rutaSprite){
    Locator::logger()->log(DEBUG,"Se va a buscar el sonido: " + rutaSprite);
    chunk = Mix_LoadWAV( rutaSprite.c_str());
    if( chunk == NULL )
    {
        Locator::logger()->log(DEBUG,"Fallo al cargar el sonido, se cargara uno por default: %s\n" + string(Mix_GetError()) );
        //chunk =  Mix_LoadWAV( rutaSprite.c_str());
    }

}

Mix_Chunk *Sonido::getChunk() {
    return this->chunk;
}
