//
// Created by felipe on 2/11/19.
//

#ifndef FINAL_FIGHT_SONIDO_H
#define FINAL_FIGHT_SONIDO_H


#include <SDL2/SDL_mixer.h>
#include <string>

using namespace std;

class Sonido  {

private:

    Mix_Chunk *chunk;

public:
    explicit Sonido(const string& rutaSonido);

    Mix_Chunk * getChunk();

    int ancho();

};


#endif //FINAL_FIGHT_SONIDO_H
