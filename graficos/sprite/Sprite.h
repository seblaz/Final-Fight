//
// Created by felipe on 11/9/19.
//


#ifndef FINAL_FIGHT_SPRITE_H
#define FINAL_FIGHT_SPRITE_H

#endif //FINAL_FIGHT_SPRITE_H


#include <SDL_render.h>
#include <SDL_system.h>
#include <string>


using namespace std;

class Sprite {

private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;

public:
    explicit Sprite(SDL_Renderer* renderer, const string& rutaSprite);

    SDL_Texture * getTexture(){
        return this->texture;
    }

};
