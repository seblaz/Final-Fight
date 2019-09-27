
#include <fstream>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Sprite.h"
#include "../servicios/Locator.h"

Sprite::Sprite(SDL_Renderer *renderer, const string &rutaSprite) :
        renderer(renderer) {
    Logger *logger = Locator::logger();
    ifstream infile(rutaSprite);
    if (!infile.good()) {
        logger->log(ERROR, "No existe el sprite:" + rutaSprite + ". Se va a cargar una textura por defecto.");

        TTF_Font *Sans = TTF_OpenFont("assets/fuentes/open-sans/OpenSans-Regular.ttf", 24);
        if (Sans == nullptr) {
            logger->log(ERROR, string("No se pudo cargar la fuente. El error fue: ").append(TTF_GetError()));
            SDL_Surface *surfaceColor = SDL_CreateRGBSurface(0, 2000, 2000,32, 0, 0, 0, 0);
            SDL_FillRect(surfaceColor, nullptr, SDL_MapRGB(surfaceColor->format, rand(), rand(), rand()));
            texture = SDL_CreateTextureFromSurface(renderer, surfaceColor); //now you can convert it into a texture
        } else {
            SDL_Color black = {0, 0, 0};
            SDL_Surface *surfaceMessage = TTF_RenderText_Solid(Sans, "No existe el sprite. No existe el sprite. No existe el sprite. No existe el sprite.", black);
            SDL_Surface *surfaceColor = SDL_CreateRGBSurface(0, 2000, 2000,32, 0, 0, 0, 0);
            SDL_FillRect(surfaceColor, nullptr, SDL_MapRGB(surfaceColor->format, rand(), rand(), rand()));
            SDL_BlitSurface(surfaceMessage, nullptr, surfaceColor, nullptr);
            texture = SDL_CreateTextureFromSurface(renderer, surfaceColor); //now you can convert it into a texture
        }
        ancho_ = 1000;

    } else {
        Locator::logger()->log(DEBUG, "Se va a instanciar el sprite: " + rutaSprite);

        SDL_Surface *sprite = IMG_Load(rutaSprite.c_str());
        ancho_ = sprite->w;
        SDL_SetColorKey(sprite, SDL_TRUE, SDL_MapRGB(sprite->format, 0X58, 0xB8, 0xF8));
        texture = SDL_CreateTextureFromSurface(renderer, sprite);
        SDL_FreeSurface(sprite);
    }
}

SDL_Texture *Sprite::getTexture() {
    return this->texture;
}

int Sprite::ancho() {
    return ancho_;
}