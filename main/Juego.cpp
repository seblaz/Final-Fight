//
// Created by sebas on 1/9/19.
//

#include <unistd.h>
#include "Juego.h"
#include <chrono>

void Juego::initialize() {
    const int SCREEN_WIDTH = 1280;
    const int SCREEN_HEIGHT = 960;

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
            _renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if(!_renderer) {
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
                exit = true;
            }
        }
    }
}

void Juego::loop() {
    const int MS_PER_FRAME = 25000; // Microseconds. 40 FPS. TODO: leer los FPS del archivo de configuracion.

    while (!exit) {
        auto start = chrono::system_clock::now();

        processInput();
        clearScene();
        update();
        render();

        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;

        const int sleep_time = MS_PER_FRAME - int(elapsed_seconds.count()) * 1000 * 1000;

        if(sleep_time > 0){ // No quitar el if. La primera vuelta suele tardar más que MS_PER_FRAME.
            usleep(sleep_time); // Microseconds.
        }
    }
}

void Juego::processInput() {
    SDL_Event e;
    if (SDL_PollEvent(&e) && (e.type == SDL_QUIT)) {
        exit = true;
    }
}

void Juego::update() {
    for (auto mapeable : mapa->devolverMapeables()) {
        mapeable->actualizar(_renderer);
    }
}

void Juego::render() {
    SDL_RenderPresent(_renderer); // Update screen
}

void Juego::finish() {
    SDL_DestroyRenderer(_renderer); // Destroy _renderer
    SDL_DestroyWindow(window); // Destroy window
    _renderer = nullptr;
    window = nullptr;

    SDL_Quit(); // Quit SDL subsystems
}

void Juego::clearScene() {
    //Se Construye el escenario
    SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(_renderer);
}

SDL_Renderer *Juego::renderer() {
    return _renderer;
}
