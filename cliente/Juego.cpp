//
// Created by sebas on 1/9/19.
//

#include "Juego.h"
#include "../servicios/Locator.h"
#include "ReceptorCliente.h"
#include <algorithm>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include "interpretes/InterpreteAutenticadorCli.h"
#include "entradas/EntradaAutenticador.h"
#include "modelos/MenuSeleccion.h"
#include "interpretes/InterpreteNuloCli.h"
#include "entradas/EntradaMenuSeleccion.h"
#include "vistas/VistaMenuSeleccion.h"
#include "pantallas/PantallaError.h"
#include "interpretes/InterpreteJuegoCli.h"
#include "entradas/EntradaJuego.h"
#include "vistas/VistaJuego.h"
#include "pantallas/PantallaJuego.h"
#include "interpretes/InterpretePuntuacionCli.h"
#include "entradas/EntradaConfirmacion.h"
#include "vistas/VistaPuntuacion.h"
#include "entradas/EntradaNula.h"
#include "vistas/VistaPlana.h"

Juego::Juego() {
    inicializarGraficos();
}

void Juego::inicializarGraficos() {
    const int SCREEN_WIDTH = Locator::configuracion()->getIntValue("/resolucion/ancho");
    const int SCREEN_HEIGHT = Locator::configuracion()->getIntValue("/resolucion/alto");

    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se inicializan los graficos.");

    //Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
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
            fuente = TTF_OpenFont("../assets/fuentes/arcadeclassic/ARCADECLASSIC.TTF", 60);
            if (!fuente) {
                Locator::logger()->log(ERROR, "Fallo cargar la fuente SDL_ttf. Error: " + string(TTF_GetError()));
                exit = true;
            }
            if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
                Locator::logger()->log(ERROR, "Fallo cargar la SDL_Mixer. Error: " + string(Mix_GetError()));
                exit = true;
            }
            Mix_Init(0);
            Mix_AllocateChannels(7);
            Locator::provide(fuente);
        }
    }
}

void Juego::agregarPantallas() {
    auto *autenticador = new Autenticador();
    auto *vistaAutenticador = new VistaAutenticador(autenticador);
    auto *interpreteAutenticador = new InterpreteAutenticadorCli(autenticador, &manager);
    auto *entradaAutenticador = new EntradaAutenticador(autenticador);
    manager.agregarPantalla(new Pantalla("autenticacion",
                                         interpreteAutenticador,
                                         entradaAutenticador,
                                         vistaAutenticador));

    auto *menu = new MenuSeleccion();
    manager.agregarPantalla(new Pantalla("menu de seleccion",
                                         new InterpreteNuloCli(),
                                         new EntradaMenuSeleccion(menu),
                                         new VistaMenuSeleccion(menu)));


    manager.agregarPantalla(new PantallaJuego("nivel1",
                                              new InterpreteJuegoCli(),
                                              new EntradaJuego(),
                                              new VistaJuego()));

    manager.agregarPantalla(new PantallaJuego("nivel2",
                                              new InterpreteJuegoCli(),
                                              new EntradaJuego(),
                                              new VistaJuego()));

    auto *puntuaciones = new PuntuacionJugadores();
    manager.agregarPantalla(new Pantalla("puntuacion1",
                                         new InterpretePuntuacionCli(puntuaciones),
                                         new EntradaConfirmacion(),
                                         new VistaPuntuacion(puntuaciones)));

    manager.agregarPantalla(new Pantalla("puntuacion2",
                                         new InterpretePuntuacionCli(puntuaciones),
                                         new EntradaConfirmacion(),
                                         new VistaPuntuacion(puntuaciones)));

    manager.agregarPantalla(new Pantalla("fin",
                                         new InterpreteNuloCli(),
                                         new EntradaNula(),
                                         new VistaPlana("/pantallas/fin/src", "/pantallas/fin/musica/src")));

    manager.agregarPantalla(new Pantalla("game over",
                                         new InterpreteNuloCli(),
                                         new EntradaConfirmacion(),
                                         new VistaPlana("/pantallas/gameOver/src", "/pantallas/gameOver/musica/src")));

    manager.agregarPantalla(new PantallaError("usuario ya conectado", "/pantallas/error/usuarioYaConectado/src"));
    manager.agregarPantalla(new PantallaError("partida llena", "/pantallas/error/partidaLlena/src"));
    manager.agregarPantalla(new PantallaError("error de conexion", "/pantallas/error/conexion/src"));
}

void Juego::loop() {

    if (exit) return;

    agregarPantallas();
    recibirEnHilo();

    /**
     * Transmision.
     */
    Locator::logger()->log(DEBUG, "Se inicia el hilo de transmisión.");
    const int MS_PER_FRAME = int(1.0 / Locator::configuracion()->getIntValue("/fps") * 1000); // Milisegundos.
    while (!exit) {
        int start = SDL_GetTicks();

        exit = manager.getActual()->procesarEntrada();

        int end = SDL_GetTicks();
        int sleepTime = MS_PER_FRAME + start - end;
        if (sleepTime > 0) SDL_Delay(sleepTime);
    }

    Locator::logger()->log(INFO, "Finaliza el hilo de transmisión.");
}

void Juego::recibir() {

    /**
     * Recepcion.
     */
    Locator::logger()->log(DEBUG, "Se inicia el hilo de recepción.");
    stringstream s;
    manager.getActual()->iniciar();
    while (!exit) {
        s.str(std::string());
        manager.getActual()->recibir(s);
        if(!Locator::socket()->estaDesconectado()){
            manager.getActual()->interpretarNombrePantalla(s);
            manager.getActual()->interpretarModelo(s);
        }
        manager.getActual()->graficar(renderer_);
        actualizarGraficos();
    }
    Locator::logger()->log(DEBUG, "Se termina el hilo de recepción.");
}

void Juego::actualizarGraficos() {
    SDL_RenderPresent(renderer_); // Update screen
    SDL_SetRenderDrawColor(renderer_, 0x0, 0x0, 0x0, 0x0);
    SDL_RenderClear(renderer_);
}

SDL_Renderer *Juego::renderer() {
    return renderer_;
}

void Juego::terminar() {
    Locator::logger()->log(INFO, "Se termina el juego.");
    Locator::logger()->log(DEBUG, "Se destruye renderer y window.");

    SDL_DestroyRenderer(renderer_); // Destroy renderer_
    SDL_DestroyWindow(window); // Destroy window
    renderer_ = nullptr;
    window = nullptr;

    TTF_CloseFont(fuente);
    Mix_CloseAudio();
    Mix_Quit(); // Quit SDL subsystems
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
}

pthread_t Juego::recibirEnHilo() {
    return lanzarHilo(bind(&Juego::recibir, this));
}
