
#include <SDL_image.h>
#include "Sprite.h"
#include "../../servicios/Locator.h"

Sprite::Sprite(SDL_Renderer *renderer, const string &rutaSprite) :
        renderer(renderer) {

    Locator::logger()->log(DEBUG, "Se va a instanciar el sprite: " + rutaSprite);

    SDL_Surface *sprite = IMG_Load(rutaSprite.c_str());
    ancho_ = sprite->w;
    SDL_SetColorKey(sprite, SDL_TRUE, SDL_MapRGB(sprite->format, 0X58, 0xB8, 0xF8));
    texture = SDL_CreateTextureFromSurface(renderer, sprite);
    SDL_FreeSurface(sprite);
}

SDL_Texture *Sprite::getTexture() {
    return this->texture;
}

int Sprite::ancho() {
    return ancho_;
}