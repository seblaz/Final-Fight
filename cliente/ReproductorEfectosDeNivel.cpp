//
// Created by poncio on 23/9/19.
//

#include <SDL2/SDL_mixer.h>
#include "ReproductorEfectosDeNivel.h"
#include "../servicios/Locator.h"


ReproductorEfectosDeNivel::ReproductorEfectosDeNivel(char * rutaMusica) {
    this->rutaMusica = rutaMusica;
};


void ReproductorEfectosDeNivel::actualizar(Entidad *entidad) {
    reproducirMusica(rutaMusica);
}

void ReproductorEfectosDeNivel::reproducirMusica(char *rutaMusica) {
    if(Mix_PlayingMusic() == 0 )
    {
        Mix_Music *gMusic;
        gMusic = Mix_LoadMUS( rutaMusica);
        Mix_PlayMusic( gMusic, -1);
    }
}
