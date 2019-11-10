//
// Created by sebas on 22/10/19.
//

#ifndef FINAL_FIGHT_FABRICADESONIDOS_H
#define FINAL_FIGHT_FABRICADESONIDOS_H

#include <unordered_map>
#include <SDL2/SDL_mixer.h>
#include "../../graficos/Sprite.h"
#include "../../sonidos/Sonido.h"

using namespace std;

class FabricaDeSonidos {

private:
    unordered_map<string, Sonido *> sonidos;

public:
    Sonido *getSoundBySrc(const string& src);
    Sonido *getSoundConfigPath(const string& path);
};


#endif //FINAL_FIGHT_FABRICADESONIDOS_H
