//
// Created by sebas on 1/9/19.
//

#include <unistd.h>
#include "Juego.h"
#include <chrono>
#include <algorithm>

Juego::Juego() {
    inicializarGraficos();
    inicializarElementos();
}

void Juego::inicializarGraficos() {
    const int SCREEN_WIDTH = Locator::configuracion()->getIntValue("/resolucion/ancho");
    const int SCREEN_HEIGHT = Locator::configuracion()->getIntValue("/resolucion/alto");

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not inicializarGraficos! SDL_Error: %s\n", SDL_GetError());
    } else {
        //Create window
        window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_RESIZABLE);
        if (window == nullptr) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        } else {
            //Get window surface
            renderer_ = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
            if (!renderer_) {
                printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
                exit = true;
            }
        }
    }
}

void Juego::loop() {
    const int MS_PER_FRAME = 1.0 / Locator::configuracion()->getIntValue("/fps") * 1000 * 1000; // Microsegundos.

    while (!exit) {
        auto start = chrono::system_clock::now();

        processInput();
        clearScene();
        actualizar();
        graficar();

        auto end = chrono::system_clock::now();
        chrono::duration<double> elapsed_seconds = end - start;

        const int sleep_time = MS_PER_FRAME - int(elapsed_seconds.count()) * 1000 * 1000;

        if (sleep_time > 0) { // No quitar el if. La primera vuelta suele tardar más que MS_PER_FRAME.
            usleep(sleep_time); // Microseconds.
        }
    }
}

void Juego::inicializarElementos() {
    mapa_ = Mapa();
}


void Juego::processInput() {
    SDL_Event e;
    if (SDL_PollEvent(&e) && (e.type == SDL_QUIT)) {
        exit = true;
    }
}

void Juego::actualizar() {
    auto mapeables = mapa().devolverMapeables();

    sort(mapeables.begin(), mapeables.end(), [](Mapeable *a, Mapeable *b) {
        return a->grafico()->profundidad() > b->grafico()->profundidad();
    });

    for (auto mapeable : mapeables) {
        mapeable->comportamiento()->actualizar();
    }

    for (auto mapeable : mapeables) {
        mapeable->fisica()->actualizar();
    }

    for (auto mapeable : mapeables) {
        mapeable->grafico()->actualizar(renderer_);
    }
}

void Juego::graficar() {
    SDL_RenderPresent(renderer_); // Update screen
}

void Juego::terminar() {
    SDL_DestroyRenderer(renderer_); // Destroy renderer_
    SDL_DestroyWindow(window); // Destroy window
    renderer_ = nullptr;
    window = nullptr;

    SDL_Quit(); // Quit SDL subsystems
}

void Juego::clearScene() {
    //Se Construye el escenario
    SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer_);
}

SDL_Renderer *Juego::renderer() {
    return renderer_;
}

Mapa &Juego::mapa() {
    return mapa_;
}

