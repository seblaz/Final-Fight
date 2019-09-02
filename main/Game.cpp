//
// Created by sebas on 1/9/19.
//

#include <unistd.h>
#include "Game.h"
#include <chrono>

void Game::initialize() {
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 960;

    //The surface contained by the window


    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    } else {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
        if (window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            //Get window surface
            screenSurface = SDL_GetWindowSurface(window);
        }
    }
}

void Game::loop() {
    const int MS_PER_FRAME = 25000; // Microseconds. 40 FPS. TODO: leer los FPS del archivo de configuracion.

    while (!exit) {
        auto start = chrono::system_clock::now();

        processInput();
        update();
        render();

        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;
        usleep(MS_PER_FRAME - elapsed_seconds.count() * 1000 * 1000); // Microseconds.
    }
}

void Game::processInput() {
    SDL_Event e;
    if (SDL_PollEvent(&e) && (e.type == SDL_QUIT)) {
        exit = true;
    }
}

void Game::update() {
    for(auto mapeable : mapa.devolverMapeables()){
        mapeable->actualizar(screenSurface);
    }
}

void Game::render() {
    SDL_UpdateWindowSurface(window); // Update the surface
}

void Game::finish() {
    SDL_DestroyWindow(window); // Destroy window
    SDL_Quit(); // Quit SDL subsystems
}

