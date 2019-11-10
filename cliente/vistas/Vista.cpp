//
// Created by sebas on 9/11/19.
//

#include <SDL_mixer.h>
#include "Vista.h"
#include "../../servicios/Locator.h"

void Vista::reproducir() {
    if (Mix_PlayingMusic() == 0) {
        const string &configPath = getConfigPathMusica();
        Mix_Music *musica = Locator::fabricaDeMusicas()->getMusicByConfigPath(configPath)->getMusic();
        if (Mix_PlayMusic(musica, 10) == -1) {
            Locator::logger()->log(ERROR, "No se pudo reproducir la música: " + string(Mix_GetError()));
        } else {
            Locator::logger()->log(DEBUG, "Inicio reproducción de musica.");
        }
    } else {
        Locator::logger()->log(ERROR, "No se pudo reproducir música, ya hay otra en reproducción.");
    }
}

int Vista::getLoops() {
    return -1;
}
