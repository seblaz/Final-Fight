//
// Created by sebas on 1/9/19.
//

#include "Juego.h"
#include "../servicios/Locator.h"
#include "ReceptorCliente.h"
#include "EntradaUsuario.h"
#include "../modelo/serializables/EventoUsuario.h"
#include <algorithm>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include "pantallas/autenticador/PantallaAutenticador.h"
#include "pantallas/ManagerPantallas.h"
#include "pantallas/juego/PantallaJuego.h"
#include "pantallas/error/PantallaError.h"

Juego::Juego() {
    inicializarGraficos();
}

void Juego::inicializarGraficos() {
    const int SCREEN_WIDTH = Locator::configuracion()->getIntValue("/resolucion/ancho");
    const int SCREEN_HEIGHT = Locator::configuracion()->getIntValue("/resolucion/alto");

    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se inicializan los graficos.");

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        logger->log(ERROR, string("SDL no pudo inicializar graficos! SDL_Error: ").append(SDL_GetError()));
        exit = true;
    } else {
        //Create window
        window = SDL_CreateWindow("Final Fight!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH,
                                  SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (window == nullptr) {
            logger->log(ERROR, string("SDL no pudo crear la ventana! SDL_Error: ").append(SDL_GetError()));
            exit = true;
        } else {
            //Get window surface
            renderer_ = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (!renderer_) {
                logger->log(ERROR, string("SDL no pudo crear el render! SDL_Error: ").append(SDL_GetError()));
                exit = true;
            }
            SDL_SetRenderDrawBlendMode(renderer_, SDL_BLENDMODE_BLEND);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) & imgFlags)) {
                logger->log(ERROR, string("SDL_image no se pudo recibir! SDL_Error: ").append(IMG_GetError()));
                exit = true;
            }
            if (TTF_Init() < 0) {
                logger->log(ERROR, string("SDL_ttf no se pudo recibir! SDL_Error: ").append(TTF_GetError()));
                exit = true;
            }
            fuente = TTF_OpenFont("../assets/fuentes/open-sans/OpenSans-Bold.ttf", 60);
            if (!fuente) {
                Locator::logger()->log(ERROR, "Fallo cargar la fuente SDL_ttf. Error: " + string(TTF_GetError()));
                exit = true;
            }
            Locator::provide(fuente);
        }
    }
}

void Juego::loop() {

    if (exit) return;

    ManagerPantallas manager;
    manager.agregarPantalla(new PantallaAutenticador("autenticador"));
    manager.agregarPantalla(new PantallaJuego("juego", &mapa_));
    manager.agregarPantalla(new PantallaError("usuario ya conectado", "/pantallas/error/usuarioYaConectado/src"));
    manager.agregarPantalla(new PantallaError("partida llena", "/pantallas/error/partidaLlena/src"));
    manager.agregarPantalla(new PantallaError("error de conexion", "/pantallas/error/conexion/src"));

    while (!exit) {
        SDL_Event *e = processInput();
        manager.getActual()->actualizar(e);
        delete e;
        graficar();
    }
    manager.getActual()->finalizar();
}

SDL_Event *Juego::processInput() {
    auto *e = new SDL_Event;
    if (SDL_PollEvent(e) && (e->type == SDL_QUIT)) {
        stringstream s;
        Accion(FIN).serializar(s);
        Locator::socket()->enviar(s);
        Locator::logger()->log(INFO, "Se cierra la aplicación voluntariamente.");
        exit = true;
    }
    return e;
}

void Juego::graficar() {
    SDL_RenderPresent(renderer_); // Update screen
    SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer_);
}

void Juego::terminar() {
    Locator::logger()->log(INFO, "Se termina el juego.");
    Locator::logger()->log(DEBUG, "Se destruye renderer y window.");

    SDL_DestroyRenderer(renderer_); // Destroy renderer_
    SDL_DestroyWindow(window); // Destroy window
    renderer_ = nullptr;
    window = nullptr;

    TTF_CloseFont(fuente);
    SDL_Quit(); // Quit SDL subsystems
}

SDL_Renderer *Juego::renderer() {
    return renderer_;
}