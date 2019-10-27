//
// Created by sebas on 22/10/19.
//

#ifndef FINAL_FIGHT_FABRICADESPRITES_H
#define FINAL_FIGHT_FABRICADESPRITES_H

#include <unordered_map>
#include "../graficos/Sprite.h"

using namespace std;

class FabricaDeSprites {

private:
    unordered_map<string, Sprite *> sprites;

public:
    Sprite *getSpriteBySrc(const string& src);
    Sprite *getSpriteConfigPath(const string& path);
};


#endif //FINAL_FIGHT_FABRICADESPRITES_H
