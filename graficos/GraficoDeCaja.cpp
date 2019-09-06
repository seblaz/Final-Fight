//
// Created by sebas on 2/9/19.
//

#include "GraficoDeCaja.h"

void GraficoDeCaja::actualizar(SDL_Renderer *renderer, Mapeable &mapeable) {
    //Load image at specified path
    SDL_Surface *loadedSurface = SDL_LoadBMP("assets/img/box.bmp");

    if (loadedSurface == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp",
               SDL_GetError());
    } else {
        texture = SDL_CreateTextureFromSurface(renderer, loadedSurface);
        if (texture == nullptr) {
            printf("Unable to create texture from %s! SDL Error: %s\n",
                   "02_getting_an_image_on_the_screen/hello_world.bmp", SDL_GetError());
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Clear screen
    SDL_RenderClear(renderer);

    //Render texture to screen
    SDL_RenderCopy(renderer, texture, nullptr, nullptr);
}

GraficoDeCaja::~GraficoDeCaja() {
    //Deallocate surface
    SDL_DestroyTexture(texture);
    texture = nullptr;
}
