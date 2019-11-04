//
// Created by poncio on 23/9/19.
//

#include <SDL2/SDL_mixer.h>
#include "ReproductorEfectosDeNivel.h"
#include "../servicios/Locator.h"

void ReproductorEfectosDeNivel::actualizar(Entidad *entidad) {
    reproducirMusica();
}

void ReproductorEfectosDeNivel::reproducirMusica() {
    if(Mix_PlayingMusic() == 0 )
    {
        Mix_Music *gMusic;
        gMusic = Mix_LoadMUS( "/home/felipe/Documentos/Final-Fight/assets/sonidos/nivel1.wav" );
        Mix_PlayMusic( gMusic, -1);
    }
}
