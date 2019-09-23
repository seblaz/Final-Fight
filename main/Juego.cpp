//
// Created by sebas on 1/9/19.
//

#include <unistd.h>
#include "Juego.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"
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
            SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);
        }
    }
}

void Juego::loop() {
    const size_t MS_PER_FRAME = 1.0 / Locator::configuracion()->getIntValue("/fps") * 1000; // Microsegundos.

    while (!exit) {
        size_t start = SDL_GetTicks();

        processInput();
        clearScene();
        actualizar();
        graficar();

        size_t end = SDL_GetTicks();
        int sleepTime = MS_PER_FRAME + start - end;

        if(sleepTime > 0){
            SDL_Delay( sleepTime );
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
    auto entidades = mapa().devolverEntidades();

    sort(entidades.begin(), entidades.end(), [](Entidad *a, Entidad *b) {
        return a->getEstado<Posicion>("posicion")->getY() > b->getEstado<Posicion>("posicion")->getY();
    });

    for (auto entidad : entidades) {
        auto comportamientos = entidad->getComportamientos();
        for(auto * comportamiento : comportamientos){
            comportamiento->actualizar(entidad);
        }
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

