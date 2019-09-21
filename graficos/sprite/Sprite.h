//
// Created by felipe on 11/9/19.
//


#ifndef FINAL_FIGHT_SPRITE_H
#define FINAL_FIGHT_SPRITE_H



#include <SDL_render.h>
#include <SDL_system.h>
#include <string>
#include "../../modelo/mapeables/Entidad.h"


using namespace std;

class Sprite : public Estado {

private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int ancho_;

public:
    explicit Sprite(SDL_Renderer* renderer, const string& rutaSprite);

    SDL_Texture * getTexture();

    int ancho();

};

#endif //FINAL_FIGHT_SPRITE_H

