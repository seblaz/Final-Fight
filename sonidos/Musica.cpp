//
// Created by felipe on 2/11/19.
//


#include "Musica.h"
#include "../servicios/Locator.h"

Musica::Musica(const string &rutaSprite){
    Locator::logger()->log(DEBUG,"Se va a buscar la musica: " + rutaSprite);
    music = Mix_LoadMUS( rutaSprite.c_str());
    if( music == NULL )
    {
        Locator::logger()->log(DEBUG,"Fallo al cargar el sonido, se cargara uno por default: %s\n" + string(Mix_GetError()) );
    }

}

Mix_Music* Musica::getMusic() {
    return this->music;
}
