//
// Created by felipe on 2/11/19.
//

#ifndef FINAL_FIGHT_MUSICA_H
#define FINAL_FIGHT_MUSICA_H


#include <SDL2/SDL_mixer.h>
#include <string>

using namespace std;

class Musica  {

private:

    Mix_Music *music;

public:
    explicit Musica(const string& rutaSprite);

    Mix_Music * getMusic();

};


#endif //FINAL_FIGHT_SONIDO_H
