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
#include <string>
#include "../modelo/Entidad.h"
#include "../graficos/Sprite.h"
#include "../graficos/GraficoDeElementosPantalla.h"

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
    SDL_Event e;

    while (!exit) {
        processInput(); //Se llama para poder cerrar el juego
        
        Usuario usuarioAux = generarPantallaDeIngreso();
        string user = usuarioAux.getUsuario();
        string pass = usuarioAux.getContrasenia();

        cout << "El nombre de usuario es: " << user << endl;
        //cin >> user;
        cout << "La contraseña es: " << pass << endl;
        //cin >> pass;

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

Usuario& Juego::generarPantallaDeIngreso() {
    Locator::logger()->log(INFO, "Se genera la pantalla de espera.");
    Configuracion *config = Locator::configuracion();
    string srcSpritePantallaIngreso = config->getValue("/pantallaDeIngreso/sprite/src");
    string srcSpriteBotonEntrar = config->getValue("/pantallaDeIngreso/botonDeEntrar/sprite/src");
    string srcSpriteBoxIdentificacion = config->getValue("/pantallaDeIngreso/identificacionUsuario/sprite/src");
    string srcSpriteBoxUsr = config->getValue("/pantallaDeIngreso/boxUsuario/sprite/src");
    string srcSpriteBoxContrasenia = config->getValue("/pantallaDeIngreso/boxContrasenia/sprite/src");
    int ancho = Locator::configuracion()->getIntValue("/resolucion/ancho");
    int alto = Locator::configuracion()->getIntValue("/resolucion/alto");
    SDL_Renderer *sdlRenderer = Locator::renderer();
    SDL_Color color = { 238, 238, 238 , 0};
    TTF_Font *gFont;
    bool exit = false;
    bool usuarioSeleccionado = false;
    bool contraseniaSeleccionada = false;
    seleccionar_box_t boxSeleccionadaRectOk;
    seleccionar_box_t boxSeleccionadaRectUsuario;
    seleccionar_box_t boxSeleccionadaRectContrasenia;
    boxSeleccionadaRectUsuario.textcolor = color;
    boxSeleccionadaRectContrasenia.textcolor = color;
    boxSeleccionadaRectUsuario.text = "";
    boxSeleccionadaRectContrasenia.text = "";

    TTF_Init();
    gFont = TTF_OpenFont( "../assets/fuentes/open-sans/OpenSans-Bold.ttf", 22 );
    if(!gFont)
        Locator::logger()->log(ERROR, "Fallo cargar la font SDL_ttf Error: ");
    else
        //cout << "Se cargo la font" << endl; //Debug

    Locator::logger()->log(DEBUG, "Se genera pantalla de ingreso");

    while (!exit) {
        SDL_Event sdlEvento;
        SDL_WaitEvent(&sdlEvento);
        Entidad *pantalla = new Entidad();
        SDL_Surface * surfaceTextoUsuario;
        SDL_Surface * surfaceTextoContrasenia;
        SDL_Texture * textureTextoUsuario = NULL;
        SDL_Texture * textureTextoContrasenia = NULL;
        SDL_Rect posicionEnPantallaIngresoUsuarioTexto;
        SDL_Rect posicionEnPantallaIngresoContraseniaTexto;
        int text_height;
        int text_width;

        //Limpieza pantalla
        SDL_SetRenderDrawColor(renderer_, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderClear(renderer_);

        //Boton entrar grafico
        auto *spriteBotonDeEntrar = new Sprite(sdlRenderer, srcSpriteBotonEntrar);
        SDL_Rect posicionEnPantallaIngresoBoton = {(int) (ancho/2.15), (int) (alto/1.15), (int) (ancho/16), (int) (alto/14)};
        auto *graficoBotonDeEntrar = new GraficoDeElementosPantalla(spriteBotonDeEntrar->getTexture(), posicionEnPantallaIngresoBoton, 1);

        pantalla->agregarEstado("spriteBotonDeEntrar", spriteBotonDeEntrar);
        pantalla->agregarComportamiento("graficoBotonDeEntrar", graficoBotonDeEntrar);

        //Box usuario grafico
        auto *spriteBoxUsuario = new Sprite(sdlRenderer, srcSpriteBoxUsr);
        SDL_Rect posicionEnPantallaIngresoUsuario = {(int) (ancho/2.8), (int) (alto/1.45), (int) (ancho/3.5), (int) (alto/13)};
        auto *graficoBoxUsuario = new GraficoDeElementosPantalla(spriteBoxUsuario->getTexture(), posicionEnPantallaIngresoUsuario, 1);

        pantalla->agregarEstado("spriteBoxUsuario", spriteBoxUsuario);
        pantalla->agregarComportamiento("graficoBoxUsuario", graficoBoxUsuario);

        //Grafico caracteres usuario
        if(boxSeleccionadaRectUsuario.text.length()) {
            cout << "Se puede" << endl;
            surfaceTextoUsuario = TTF_RenderText_Solid(gFont, boxSeleccionadaRectUsuario.text.c_str(), boxSeleccionadaRectUsuario.textcolor);
            textureTextoUsuario = SDL_CreateTextureFromSurface(sdlRenderer, surfaceTextoUsuario);
            text_width = surfaceTextoUsuario->w;
            text_height = surfaceTextoUsuario->h;
            posicionEnPantallaIngresoUsuarioTexto = posicionEnPantallaIngresoUsuario;
            posicionEnPantallaIngresoUsuarioTexto.w = text_width;
            posicionEnPantallaIngresoUsuarioTexto.h = text_height;
            posicionEnPantallaIngresoUsuarioTexto.x += (int) ancho/14;
            posicionEnPantallaIngresoUsuarioTexto.y += (int) alto/72;
            SDL_FreeSurface(surfaceTextoUsuario);
        }

        //Box Contrasenia
        auto *spriteBoxContrasenia = new Sprite(sdlRenderer, srcSpriteBoxContrasenia);
        SDL_Rect posicionEnPantallaIngresoContrasenia = {(int) (ancho/2.8), (int) (alto/1.3), (int) (ancho/3.5), (int) (alto/13)};
        auto *graficoBoxContrasenia = new GraficoDeElementosPantalla(spriteBoxContrasenia->getTexture(), posicionEnPantallaIngresoContrasenia, 1);

        pantalla->agregarEstado("spriteBoxContrasenia", spriteBoxContrasenia);
        pantalla->agregarComportamiento("graficoBoxContrasenia", graficoBoxContrasenia);

        //Grafico caracteres contraseña
        if(boxSeleccionadaRectContrasenia.text.length()) {
            surfaceTextoContrasenia = TTF_RenderText_Solid(gFont, boxSeleccionadaRectContrasenia.text.c_str(), boxSeleccionadaRectContrasenia.textcolor);
            textureTextoContrasenia = SDL_CreateTextureFromSurface(sdlRenderer, surfaceTextoContrasenia);
            text_width = surfaceTextoContrasenia->w;
            text_height = surfaceTextoContrasenia->h;
            posicionEnPantallaIngresoContraseniaTexto = posicionEnPantallaIngresoContrasenia;
            posicionEnPantallaIngresoContraseniaTexto.w = text_width;
            posicionEnPantallaIngresoContraseniaTexto.h = text_height;
            posicionEnPantallaIngresoContraseniaTexto.x += (int) ancho/11;
            posicionEnPantallaIngresoContraseniaTexto.y += (int) alto/72;
            SDL_FreeSurface(surfaceTextoContrasenia);
        }

        //Box identificacion grafico
        auto *spriteBoxIdentificacion = new Sprite(sdlRenderer, srcSpriteBoxIdentificacion);
        SDL_Rect posicionEnPantallaIngresoBoxIdentificacion = {(int) (ancho/3), (int) (alto/1.7), (int) (ancho/3), (int) (alto/2.45)};
        auto *graficoBoxIdentificacion = new GraficoDeElementosPantalla(spriteBoxIdentificacion->getTexture(), posicionEnPantallaIngresoBoxIdentificacion, 1);

        pantalla->agregarEstado("spriteBoxIdentificacion", spriteBoxIdentificacion);
        pantalla->agregarComportamiento("graficoBoxIdentificacion", graficoBoxIdentificacion);

        //Pantalla grafico
        auto *spritePantallaIngreso = new Sprite(sdlRenderer, srcSpritePantallaIngreso);
        SDL_Rect posicionEnPantallaIngreso = {0, 0, ancho, alto};
        auto *graficoPantalla = new GraficoDeElementosPantalla(spritePantallaIngreso->getTexture(), posicionEnPantallaIngreso, 1);

        pantalla->agregarEstado("spritePantallaIngreso", spritePantallaIngreso);
        pantalla->agregarComportamiento("graficoPantalla", graficoPantalla);

        //Inicializacion Boxes
        boxSeleccionadaRectOk.rect = posicionEnPantallaIngresoBoton;
        boxSeleccionadaRectUsuario.rect = posicionEnPantallaIngresoUsuario;
        boxSeleccionadaRectContrasenia.rect = posicionEnPantallaIngresoContrasenia;

        switch (sdlEvento.type) {
            case SDL_QUIT:
                exit = true;
                break;
            case SDL_MOUSEBUTTONDOWN:
                //Pantalla Ok seleccionada
                if(boxSeleccionada(&boxSeleccionadaRectOk, &sdlEvento))
                    exit = true;

                //Ingreso de caracteres pantalla usuario
                if(boxSeleccionada(&boxSeleccionadaRectUsuario, &sdlEvento)){
                    usuarioSeleccionado = true;
                    contraseniaSeleccionada = false;
                }

                //Ingreso de caracteres pantalla contraseña
                if(boxSeleccionada(&boxSeleccionadaRectContrasenia, &sdlEvento)) {
                    contraseniaSeleccionada = true;
                    usuarioSeleccionado = false;
                }
                break;
            case SDL_TEXTINPUT:
                //Acoplo caracteres usuario
                if(usuarioSeleccionado && boxSeleccionadaRectUsuario.text.length() <= CANT_MAX_CARACTERES_USUARIO)
                    boxSeleccionadaRectUsuario.text.append(sdlEvento.text.text);

                //Acoplo caracteres contraseña
                if(contraseniaSeleccionada && boxSeleccionadaRectContrasenia.text.length() <= CANT_MAX_CARACTERES_CONTRASENIA)
                    boxSeleccionadaRectContrasenia.text.append(sdlEvento.text.text);

                break;
            case SDL_KEYDOWN:

                //Retroceso usuario
                if (usuarioSeleccionado && sdlEvento.key.keysym.sym == SDLK_BACKSPACE && boxSeleccionadaRectUsuario.text.size())
                   boxSeleccionadaRectUsuario.text.pop_back();

                //Cambio usuario -> contraseña
                else if(usuarioSeleccionado && sdlEvento.key.keysym.sym == SDLK_TAB) {
                    usuarioSeleccionado = false;
                    contraseniaSeleccionada = true;
                }

                //Retroceso contraseña
                else if (contraseniaSeleccionada && sdlEvento.key.keysym.sym == SDLK_BACKSPACE && boxSeleccionadaRectContrasenia.text.size())
                    boxSeleccionadaRectContrasenia.text.pop_back();
                break;
        }
        
        //Actualizar
        auto comportamientos = pantalla->getComportamientos();
        for (auto *comportamiento : comportamientos) {
            comportamiento->actualizar(pantalla);
        }

        //Graficar
        if(textureTextoUsuario)
            SDL_RenderCopy(sdlRenderer, textureTextoUsuario, NULL, &posicionEnPantallaIngresoUsuarioTexto);
        if(textureTextoContrasenia)
            SDL_RenderCopy(sdlRenderer, textureTextoContrasenia, NULL, &posicionEnPantallaIngresoContraseniaTexto);
        SDL_RenderPresent(sdlRenderer); // Update screen

        //Quit

        //Deletes
        SDL_DestroyTexture(textureTextoUsuario);
        SDL_DestroyTexture(textureTextoContrasenia);
        delete pantalla;
        delete graficoBotonDeEntrar;
        delete graficoBoxUsuario;
        delete graficoBoxIdentificacion;
        delete graficoPantalla;
        delete graficoBoxContrasenia;
        delete spriteBotonDeEntrar;
        delete spriteBoxUsuario;
        delete spriteBoxIdentificacion;
        delete spritePantallaIngreso;
        delete spriteBoxContrasenia;
        //delete textureTextoUsuario;
    }
    TTF_CloseFont( gFont );
    static Usuario usr;
    usr.setUsuario(boxSeleccionadaRectUsuario.text);
    usr.setContrasenia(boxSeleccionadaRectContrasenia.text); //"p"

    //Debug
    cout << "La contraseña ingresa por teclado es: " << boxSeleccionadaRectContrasenia.text << endl;

    return usr;
}

bool boxSeleccionada(seleccionar_box_t *boxSeleccionada, SDL_Event *event) {
    if (/*event->type == SDL_WINDOWEVENT &&
        event->window.event == SDL_WINDOWEVENT_EXPOSED &&*/
            _boxSeleccionadaRect(event->button.x, event->button.y,
                                 &boxSeleccionada->rect))
        return true;

    return false;
}

bool _boxSeleccionadaRect(int x, int y, SDL_Rect *rect)
{
    return x >= rect->x && x < rect->x + rect->w &&
           y >= rect->y && y < rect->y + rect->h;
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

SDL_Event Juego::processInput() {
    static SDL_Event e;
    if (SDL_PollEvent(&e) && (e.type == SDL_QUIT)) {
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
