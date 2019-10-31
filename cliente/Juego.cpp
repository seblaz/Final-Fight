//
// Created by sebas on 1/9/19.
//

#include "Juego.h"
#include "../servicios/Locator.h"
#include "ReceptorCliente.h"
#include "EntradaUsuario.h"
#include "../usuario/Usuario.h"
#include "../modelo/serializables/EventoUsuario.h"
#include <algorithm>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <string>
#include "../graficos/GraficoDePantalla.h"
#include "Autenticador.h"

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
            font = TTF_OpenFont("../assets/fuentes/open-sans/OpenSans-Bold.ttf", 22);
            if (!font) {
                Locator::logger()->log(ERROR, "Fallo cargar la fuente SDL_ttf. Error: " + string(TTF_GetError()));
                exit = true;
            }
        }
    }
}

bool Juego::validarUserPass() {
    Locator::logger()->log(INFO, "Se genera la pantalla de autenticación.");
    Autenticador autenticador;

    while (!exit) {
        SDL_Event *e = processInput();
        Usuario *usuarioIngresado = autenticador.getUsuario(e);
        delete e;
        if (usuarioIngresado) {
            string user = usuarioIngresado->getUsuario();
            string pass = usuarioIngresado->getContrasenia();

            Socket *socket = Locator::socket();

            stringstream userStream;
            Accion enviarUsuario(ENVIAR_USUARIO);
            enviarUsuario.serializar(userStream);

            Usuario usuario(user, pass);
            usuario.serializar(userStream);
            socket->enviar(userStream);

            stringstream streamEvento;
            socket->recibir(streamEvento);
            EventoUsuario evento;
            evento.deserializar(streamEvento);

            switch (evento.evento()) {
                case CONTRASENIA_INCORRECTA:
                    Locator::logger()->log(ERROR, "Contraseña incorrecta.");
//                contraseniaIncorrecta = true;
                    break;
                case USUARIO_YA_CONECTADO:
                    Locator::logger()->log(ERROR, "El usuario ya se encuentra conectado en otro cliente.");
                    GraficoDePantalla::graficarPantalla("/pantallaUsuarioYaConectado/src");

//                while(true) {
//                    e = this->processInput();
//                    if ( e.type == SDL_QUIT ){
//                        return false;
//                    }
//                }
                case PARTIDA_LLENA:
                    Locator::logger()->log(ERROR, "La partida se encuentra llena.");
                    GraficoDePantalla::graficarPantalla("/pantallaPartidaLlena/src");

//                while(true) {
//                    e = this->processInput();
//                    if ( e.type == SDL_QUIT ){
//                        return false;
//                    }
//                }
                case CONECTADO:
                    Locator::logger()->log(INFO, "El usuario se conectó correctamente.");
                    return true;
            }
        }
    }
    return false;
}


bool boxSeleccionada(seleccionar_box_t *boxSeleccionada, SDL_Event *event) {
    return _boxSeleccionadaRect(event->button.x, event->button.y, &boxSeleccionada->rect);

}

bool _boxSeleccionadaRect(int x, int y, SDL_Rect *rect) {
    return x >= rect->x && x < rect->x + rect->w &&
           y >= rect->y && y < rect->y + rect->h;
}

void Juego::loop() {

    if (exit || !validarUserPass()) return;

    getEvent = SDL_PollEvent;
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

        if (!receptor.conexionEstaActiva()) {
            GraficoDePantalla::graficarPantalla("/pantallaErrorDeConexion/src");
        } else {
            receptor.devolverStreamMasReciente(s);
            actualizador.actualizarEntidades(s, &trasmision);
            clearScene();
            actualizar();
            graficar();
        }

    }
    trasmision.finalizar();
    receptor.finalizar();
    pthread_join(hiloTransmision, nullptr);
    pthread_join(hiloRecepcion, nullptr);

}

SDL_Event *Juego::processInput() {
    auto *e = new SDL_Event;
    if (getEvent(e) && (e->type == SDL_QUIT)) {
        stringstream s;
        Accion(FIN).serializar(s);
        Locator::socket()->enviar(s);
        Locator::logger()->log(INFO, "Se cierra la aplicación voluntariamente.");
        exit = true;
    }
    return e;
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

    TTF_CloseFont(font);
    SDL_Quit(); // Quit SDL subsystems
}

SDL_Renderer *Juego::renderer() {
    return renderer_;
}

Mapa &Juego::mapa() {
    return mapa_;
}