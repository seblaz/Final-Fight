
#include <SDL_image.h>
#include "Sprite.h"

Sprite::Sprite(SDL_Renderer* renderer, string rutaSprite) :
        renderer(renderer) {

    SDL_Surface *sprite = IMG_Load(rutaSprite.c_str());
    SDL_SetColorKey(sprite, SDL_TRUE, SDL_MapRGB(sprite->format, 0X58, 0xB8, 0xF8));
    texture = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_FreeSurface(sprite);

}
