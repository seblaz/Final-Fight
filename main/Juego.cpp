//
// Created by sebas on 1/9/19.
//

#include <unistd.h>
#include "Juego.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"
#include "../cliente/ReceptorCliente.h"
#include "../cliente/EntradaUsuario.h"
#include "../usuario/Usuario.h"
#include "../modelo/EventoUsuario.h"
#include <algorithm>
#include <SDL_image.h>
#include <SDL_ttf.h>

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
        }
    }
}

void Juego::validarUserPass() {
    bool exit = false;

    while (!exit) {
        processInput();
        string user;
        string pass;


        cout << "Ingrese nombre de usuario" << endl;
        cin >> user;
        cout << "Ingrese contraseña" << endl;
        cin >> pass;

        Usuario usuario(user, pass);
        stringstream userStream;
        usuario.serializar(userStream);
        Socket socket = Locator::socket();
        socket.enviar(userStream);

        stringstream streamEvento;
        socket.recibir(streamEvento);
        EventoUsuario evento;
        evento.deserializar(streamEvento);

        switch (evento.evento()){
            case CONTRASENIA_INCORRECTA:
                Locator::logger()->log(ERROR, "Contraseña incorrecta.");
                break;
            case USUARIO_YA_CONECTADO:
                Locator::logger()->log(ERROR, "El usuario ya se encuentra conectado en otro cliente.");
                std::exit(0);
            case PARTIDA_LLENA:
                Locator::logger()->log(ERROR, "La partida se encuentra llena.");
                std::exit(0);
            case CONECTADO:
                Locator::logger()->log(INFO, "El usuario se conectó correctamente.");
                exit = true;
                break;
        }
    }
}

void Juego::loop() {

    validarUserPass();

    exit = false;
    ActualizadorCliente actualizador(&mapa_);
    ReceptorCliente receptor(Locator::socket());
    pthread_t hiloRecepcion = receptor.recibirEnHilo();

    /**
    * Transmisión de acciones.
    */
    EntradaNula entrada;
    TrasmisionCliente trasmision(Locator::socket(), &entrada);
    pthread_t hiloTransmision = trasmision.transmitirEnHilo();

    while (!exit) {
        processInput();
        stringstream s;

        if (!receptor.conexionEstaActiva()) break;
        receptor.devolverStreamMasReciente(s);
        actualizador.actualizarEntidades(s, &trasmision);
        clearScene();
        actualizar();
        graficar();
    }

    pthread_join(hiloTransmision, nullptr);
    pthread_join(hiloRecepcion, nullptr);
}

void Juego::processInput() {
    SDL_Event e;
    if (SDL_PollEvent(&e) && (e.type == SDL_QUIT)) {
        exit = true;
    }
}

void Juego::clearScene() {
    //Se Construye el escenario
    SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(renderer_);
}

void Juego::actualizar() {
    auto entidades = mapa().devolverEntidades();

    sort(entidades.begin(), entidades.end(), [](Entidad *a, Entidad *b) {
        return a->getEstado<Posicion>("posicion")->getY() > b->getEstado<Posicion>("posicion")->getY();
    });

    for (auto entidad : entidades) {
        auto comportamientos = entidad->getComportamientos();
        for (auto *comportamiento : comportamientos) {
            comportamiento->actualizar(entidad);
        }
    }
}

void Juego::graficar() {
    SDL_RenderPresent(renderer_); // Update screen
}

void Juego::terminar() {
    Locator::logger()->log(INFO, "Se termina el juego.");
    Locator::logger()->log(DEBUG, "Se destruye renderer y window.");

    SDL_DestroyRenderer(renderer_); // Destroy renderer_
    SDL_DestroyWindow(window); // Destroy window
    renderer_ = nullptr;
    window = nullptr;

    SDL_Quit(); // Quit SDL subsystems
}

SDL_Renderer *Juego::renderer() {
    return renderer_;
}

Mapa &Juego::mapa() {
    return mapa_;
}

//nombreJugador Juego::menuPrincipal(){
//    Locator::logger()->log(INFO, "Se carga menu Principal");
//    Configuracion *config = Locator::configuracion();
//    string srcSprite = config->getValue("/pantallaPrincipal/sprite/src");
//    SDL_Renderer *renderer = Locator::renderer();
//    const int SCREEN_WIDTH = Locator::configuracion()->getIntValue("/resolucion/ancho");
//    const int SCREEN_HEIGHT = Locator::configuracion()->getIntValue("/resolucion/alto");
//    SDL_Event e;
//    bool quit = false;
//    char *srcSpritesJugadores[] = {
//        "assets/varios/selectorJugadorGuy.png",
//        "assets/varios/selectorJugadorCody.png",
//        "assets/varios/selectorJugadorHaggar.png",
//        "assets/varios/selectorJugadorMaki.png"
//    };
//    string srcSpriteSelector;
//    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);
//
//    while (!quit){
//        while(SDL_PollEvent(&e))
//        if (e.key.keysym.sym == SDLK_DOWN)
//            quit = true;
//
//        SDL_Surface * window_surface = SDL_GetWindowSurface(window);
//        int flags = IMG_INIT_JPG | IMG_INIT_PNG;
//        int initted = IMG_Init(flags);
//        SDL_Surface * image_surface = IMG_Load(srcSprite.c_str());
//
//        SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image_surface);
//        SDL_RenderCopy(renderer, texture, NULL, NULL);
//        SDL_RenderPresent(renderer);
//        SDL_DestroyTexture(texture);
//        SDL_FreeSurface(image_surface);
//
//        clearScene();
//    }
//    quit = false;
//    int pos = 3;
//    while (!quit){
//        while(SDL_PollEvent(&e)) {
//            if(e.key.keysym.sym == SDLK_LEFT && pos > 0)
//                pos--;
//            if(e.key.keysym.sym == SDLK_RIGHT && pos < CANTIDAD_JUGADORES)
//                pos++;
//
//            if(e.key.keysym.sym == SDLK_UP)
//                quit = true;
//            //printf("%s\n", srcSprite.c_str());
//            SDL_Surface * window_surface = SDL_GetWindowSurface(window);
//            int flags = IMG_INIT_JPG | IMG_INIT_PNG;
//            int initted = IMG_Init(flags);
//            srcSpriteSelector = srcSpritesJugadores[pos];
//
//            SDL_Surface * image_surface = IMG_Load(srcSpriteSelector.c_str());
//
//            SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, image_surface);
//            SDL_RenderCopy(renderer, texture, NULL, NULL);
//            SDL_RenderPresent(renderer);
//            SDL_DestroyTexture(texture);
//            SDL_FreeSurface(image_surface);
//        }
//        clearScene();
//    }
//
//    return (nombreJugador) pos;
//}
