//
// Created by felipe on 22/9/19.
//

#include <random>
#include "Nivel.h"
#include "../modelo/Posicion.h"
#include "../graficos/Sprite.h"
#include "../modelo/Orientacion.h"
#include "../estados/Parado.h"
#include "../estados/ia/Patrullar.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../graficos/Grafico.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../graficos/GraficoDeEscenario.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"
#include "../graficos/FabricaDeAnimacionesDeCaja.h"
#include "../graficos/FabricaDeAnimacionesDeCuchillo.h"
#include "../graficos/FabricaDeAnimacionesDePoison.h"
#include "../servicios/Locator.h"
#include "../graficos/GraficoDeTransicion.h"

// TODO: usar esto.
//    //Generador de cajas
//    int cantidadDeCajas;
//    try {
//        cantidadDeCajas = Locator::configuracion()->getIntValue(PATH_XML_CANTIDAD_CAJA);
//        Locator::logger()->log(DEBUG,"Se encontro el path para leer la cantidad de cajas");
//        Locator::logger()->log(INFO,"Se van a generar:" + to_string(cantidadDeCajas) + " cajas");
//
//    } catch(std::invalid_argument){
//        Locator::logger()->log(ERROR,"No se encontro el path para obtener la cantidad de cajas a generar");
//        Locator::logger()->log(DEBUG,"Se generara por defecto 1 caja");
//        cantidadDeCajas = 1;
//    }
//
//    int cantidadDeCuchillos;
//    try {
//        cantidadDeCuchillos = Locator::configuracion()->getIntValue(PATH_XML_CANTIDAD_CUCHILLO);
//        Locator::logger()->log(DEBUG,"Se encontro el path para leer la cantidad de cuchillos");
//        Locator::logger()->log(INFO,"Se van a generar:" + to_string(cantidadDeCuchillos) + " cuchillos");
//
//    } catch(std::invalid_argument){
//        Locator::logger()->log(ERROR,"No se encontro el path para obtener la cantidad de cuchillos a generar");
//        Locator::logger()->log(DEBUG,"Se generara por defecto 1 cuchillo");
//        cantidadDeCuchillos = 1;
//    }
//

Entidad *Nivel::generarJugador(Mapa *mapa) {
    SDL_Renderer *sdlRenderer = Locator::renderer();

    auto* jugador = mapa->crearEntidad();
    auto* posicion = new Posicion(200, 100, 0);
    auto *velocidad = new Velocidad();
    auto *spriteJugador = new Sprite(sdlRenderer, "assets/personajes/cody.png");
    auto *orientacion = new Orientacion;
    auto *animacion = FabricaDeAnimacionesDeCody::parado();
    EstadoDePersonaje *estado = new Parado();
    auto *fisica = new FisicaDePersonaje();
    auto *grafico = new Grafico();

    jugador->agregarEstado("posicion", posicion);
    jugador->agregarEstado("velocidad", velocidad);
    jugador->agregarEstado("sprite", spriteJugador);
    jugador->agregarEstado("orientacion", orientacion);
    jugador->agregarEstado("animacion", animacion);
    jugador->agregarComportamiento("estado", estado);
    jugador->agregarComportamiento("fisica", fisica);
    jugador->agregarComportamiento("grafico", grafico);

    return jugador;
}

int generarPosicionX(int frontera) {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(400, frontera - 400);
    return dist(mt);
}

int generarPosicionY(int frontera) {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(20, frontera - 20);
    return dist(mt);
}

void Nivel::generarNivel(const string &nivel, Mapa *mapa, Entidad *jugador) {
    SDL_Renderer *sdlRenderer = Locator::renderer();
    Entidad *escenario = generarEscenario(nivel, sdlRenderer, mapa);

    /**
     * Dependencias.
     */
    auto *posicionDeJugador = jugador->getEstado<Posicion>("posicion");
    auto *posicionDeEscenario = escenario->getEstado<Posicion>("posicion");
    escenario->agregarEstado("posicion de jugador", posicionDeJugador);
    jugador->agregarEstado("posicion de escenario", posicionDeEscenario);

    generarCajas(nivel, sdlRenderer, mapa, posicionDeEscenario);
    generarCuchillos(nivel, sdlRenderer, mapa, posicionDeEscenario);
    generarEnemigo(nivel, sdlRenderer, mapa, posicionDeEscenario);
    generarTransicion(nivel, sdlRenderer, mapa, posicionDeJugador);
}

Entidad * Nivel::generarEscenario(const string &nivel, SDL_Renderer *sdlRenderer, Mapa *mapa) {
    /**
     * Leer configuracion de escenario.
     */
    Configuracion *config = Locator::configuracion();
    string srcSprite = config->getValue("/niveles/" + nivel + "/escenario/sprite/src");
    int profundidad = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");
    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    int cantidadDeCapas = config->getIntValue("/niveles/" + nivel + "/escenario/sprite/capas/cantidad");

    Entidad *escenario = mapa->crearEntidad();
    auto *posicion = new Posicion(0, profundidad, 0);
    auto *sprite = new Sprite(sdlRenderer, srcSprite);
    auto *fisica = new FisicaDeEscenario(anchoNivel);

    vector<SDL_Texture *> sprites(cantidadDeCapas);
    vector<SDL_Rect> posicionesSprite(cantidadDeCapas);
    vector<float> distanciasAlFondo(cantidadDeCapas);

    for(int i = 0; i < cantidadDeCapas; i++){
        int x = config->getIntValue("/niveles/" + nivel + "/escenario/sprite/capas/capa" + to_string(i) + "/x");
        int y = config->getIntValue("/niveles/" + nivel + "/escenario/sprite/capas/capa" + to_string(i) + "/y");
        int alto = config->getIntValue("/niveles/" + nivel + "/escenario/sprite/capas/capa" + to_string(i) + "/alto");
        float distanciaAlFondo = config->getFloatValue("/niveles/" + nivel + "/escenario/sprite/capas/capa" + to_string(i) + "/distanciaAlFondo");

        sprites[i] = sprite->getTexture();
        posicionesSprite[i] = {x, y, 0, alto};
        distanciasAlFondo[i] = distanciaAlFondo;
    }

    float escalaHorizontal = (float)anchoNivel / (float)sprite->ancho();
    auto *grafico = new GraficoDeEscenario(sprites, posicionesSprite, distanciasAlFondo, escalaHorizontal);

    escenario->agregarEstado("posicion", posicion);
    escenario->agregarEstado("sprite", sprite);
    escenario->agregarComportamiento("fisica", fisica);
    escenario->agregarComportamiento("grafico", grafico);

    return escenario;
}

void Nivel::generarCajas(const string &nivel, SDL_Renderer *sdlRenderer, Mapa *mapa, Posicion *posicionDeEscenario) {
    Configuracion *config = Locator::configuracion();
    string srcSprite = config->getValue("/niveles/" + nivel + "/escenario/objetos/caja/sprite/src");
    int cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/objetos/caja/cantidad");
    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    int profundidadNivel = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");

    auto *spriteCaja = new Sprite(sdlRenderer, srcSprite);
    auto *graficoDeCaja = new Grafico();
    auto *animacionCaja = FabricaDeAnimacionesDeCaja::standby();

    for (int i = 1; i <= cantidad; i++) {
        Locator::logger()->log(INFO, "Se inicia la construccion de la cajaRandom:" + to_string(i));
        Entidad *cajaRandom = mapa->crearEntidad();

        auto *posicionCajaRandom = new Posicion(generarPosicionX(anchoNivel), generarPosicionY(profundidadNivel), 0);
        cajaRandom->agregarEstado("posicion", posicionCajaRandom);
        cajaRandom->agregarEstado("sprite", spriteCaja);
        cajaRandom->agregarEstado("animacion", animacionCaja);
        cajaRandom->agregarEstado("posicion de escenario", posicionDeEscenario);
        cajaRandom->agregarComportamiento("grafico", graficoDeCaja);
    }
}

void Nivel::generarCuchillos(const string &nivel, SDL_Renderer *sdlRenderer, Mapa *mapa, Posicion *posicionDeEscenario) {
    Configuracion *config = Locator::configuracion();
    string srcSprite = config->getValue("/niveles/" + nivel + "/escenario/objetos/cuchillo/sprite/src");
    int cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/objetos/cuchillo/cantidad");
    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    int profundidadNivel = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");

    auto *spriteCuchillo = new Sprite(sdlRenderer, srcSprite);
    auto *animacionCuchillo = FabricaDeAnimacionesDeCuchillo::standby();
    auto *graficoDeCuchillo = new Grafico();

    for (int i = 1; i <= cantidad; i++) {
        Locator::logger()->log(INFO, "Se inicia la construccion de la cuchilloRandom:" + to_string(i));

        Entidad *cuchilloRandom = mapa->crearEntidad();

        auto *posicionCuchilloRandom = new Posicion(generarPosicionX(anchoNivel), generarPosicionY(profundidadNivel), 0);
        cuchilloRandom->agregarEstado("posicion", posicionCuchilloRandom);
        cuchilloRandom->agregarEstado("sprite", spriteCuchillo);
        cuchilloRandom->agregarEstado("animacion", animacionCuchillo);
        cuchilloRandom->agregarEstado("posicion de escenario", posicionDeEscenario);
        cuchilloRandom->agregarComportamiento("grafico", graficoDeCuchillo);
    }
}

void Nivel::generarEnemigo(const string &nivel, SDL_Renderer *sdlRenderer, Mapa *mapa, Posicion *posicionDeEscenario) {
    Entidad *enemigo = mapa->crearEntidad();

    auto *posicionDeEnemigo = new Posicion(600, 100, 0);
    auto *spriteEnemigo = new Sprite(sdlRenderer, "assets/personajes/poison.png");
    auto *velocidadDeEnemigo = new Velocidad();
    auto *animacionDeEnemigo = FabricaDeAnimacionesDePoison::caminando();
    auto *orientacionDeEnemigo = new Orientacion;
    auto *estadoDeEnemigo = new Patrullar();
    auto *fisicaDeEnemigo = new FisicaDePersonaje();
    auto *graficoDeEnemigo = new Grafico();

    enemigo->agregarEstado("posicion", posicionDeEnemigo);
    enemigo->agregarEstado("sprite", spriteEnemigo);
    enemigo->agregarEstado("velocidad", velocidadDeEnemigo);
    enemigo->agregarEstado("animacion", animacionDeEnemigo);
    enemigo->agregarEstado("posicion de escenario", posicionDeEscenario);
    enemigo->agregarEstado("orientacion", orientacionDeEnemigo);
    enemigo->agregarComportamiento("estado", estadoDeEnemigo);
    enemigo->agregarComportamiento("fisica", fisicaDeEnemigo);
    enemigo->agregarComportamiento("grafico", graficoDeEnemigo);
}

void Nivel::generarTransicion(const string &nivel, SDL_Renderer *sdlRenderer, Mapa *mapa, Posicion* posicionDeJugador) {
    Entidad *transicion = mapa->crearEntidad();
    int anchoDeNivel = Locator::configuracion()->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    auto *posicion = new Posicion(0, 1, 0);
    auto *grafico = new GraficoDeTransicion(anchoDeNivel);

    transicion->agregarEstado("posicion", posicion);
    transicion->agregarEstado("posicion de jugador", posicionDeJugador);
    transicion->agregarComportamiento("grafico", grafico);
}
