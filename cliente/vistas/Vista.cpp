//
// Created by sebas on 9/11/19.
//

#include <SDL_mixer.h>
#include "Vista.h"
#include "../../servicios/Locator.h"

void Vista::reproducir() {
    if (Mix_PlayingMusic() == 0) {
        const string &configPath = getConfigPathMusica();
        Mix_PlayMusic(Locator::fabricaDeMusicas()->getMusicByConfigPath(configPath)->getMusic(), getLoops());
    }
}

int Vista::getLoops() {
    return -1;
}
