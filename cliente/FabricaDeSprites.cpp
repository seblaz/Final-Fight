//
// Created by sebas on 22/10/19.
//

#include "FabricaDeSprites.h"
#include "../servicios/Locator.h"

Sprite *FabricaDeSprites::getSpriteBySrc(const string& src) {
    if(sprites.find(src) == sprites.end()){
        SDL_Renderer *renderer = Locator::renderer();
        sprites[src] = new Sprite(renderer, src);
    }
    return sprites[src];
}

Sprite* FabricaDeSprites::getSpriteConfigPath(string path){
//    return getSpriteBySrc();
    return nullptr;
}
