//
// Created by sebas on 1/9/19.
//

#include "Graphics.h"

void Graphics::actualizar(SDL_Surface *surface, Mapeable &mapeable) {
    gHelloWorld = SDL_LoadBMP("assets/img/box.bmp");
    if (gHelloWorld == nullptr) {
        printf("Unable to load image %s! SDL Error: %s\n", "02_getting_an_image_on_the_screen/hello_world.bmp",
               SDL_GetError());
    } else {
        SDL_BlitSurface(gHelloWorld, nullptr, surface, nullptr);
    }
}

Graphics::~Graphics() {
    //Deallocate surface
    SDL_FreeSurface(gHelloWorld);
    gHelloWorld = nullptr;
}
