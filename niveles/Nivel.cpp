//DEBUG
// Created by felipe on 22/9/19.
//

#include <random>
#include "Nivel.h"
#include "../modelo/Posicion.h"
#include "../graficos/Sprite.h"
#include "../modelo/Orientacion.h"
#include "../estados/Reposando.h"
#include "../comportamiento/Patrullar.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../graficos/Grafico.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../graficos/GraficoDeEscenario.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeCody.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeCaja.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeCuchillo.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDePoison.h"
#include "../servicios/Locator.h"
#include "../graficos/GraficoDeTransicion.h"
#include "../estados/Caminando.h"

Entidad *Nivel::generarJugador(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se genera jugador principal.");

    SDL_Renderer *sdlRenderer = Locator::renderer();

    auto* jugador = mapa->crearJugador();
    auto* posicion = new Posicion(200, 100, 0);
    auto *velocidad = new Velocidad();
    auto *spriteJugador = new Sprite(sdlRenderer, "assets/personajes/cody.png");
    auto *orientacion = new Orientacion;
    auto *fabricaDeAnimaciones = new FabricaDeAnimacionesDeCody();
    auto *animacion = fabricaDeAnimaciones->reposando();
    EstadoDePersonaje *estado = new Reposando();
    auto *fisica = new FisicaDePersonaje();
    auto *grafico = new Grafico();
    auto *entradaJugador = new EntradaJugador();

    jugador->agregarEstado("posicion", posicion);
    jugador->agregarEstado("velocidad", velocidad);
    jugador->agregarEstado("sprite", spriteJugador);
    jugador->agregarEstado("orientacion", orientacion);
    jugador->agregarEstado("animacion", animacion);
    jugador->agregarEstado("estado", estado);
    jugador->agregarEstado("fabrica de animaciones", fabricaDeAnimaciones);
    jugador->agregarComportamiento("fisica", fisica);
    jugador->agregarComportamiento("grafico", grafico);
    jugador->agregarComportamiento("entrada jugador", entradaJugador);

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
    Locator::logger()->log(DEBUG, "Se genera " + nivel);

    SDL_Renderer *sdlRenderer = Locator::renderer();
    Entidad *escenario = generarEscenario(nivel, sdlRenderer, mapa);

    /**
     * Dependencias.
     */
    auto *posicionDeJugador = jugador->getEstado<Posicion>("posicion");
    auto *posicionDeEscenario = escenario->getEstado<Posicion>("posicion");
    escenario->agregarEstado("posicion de jugador", posicionDeJugador);
    jugador->agregarEstado("posicion de escenario", posicionDeEscenario);
    posicionDeJugador->x = 300;
    posicionDeJugador->y = 100;

    generarCajas(nivel, sdlRenderer, mapa, posicionDeEscenario);
    generarCuchillos(nivel, sdlRenderer, mapa, posicionDeEscenario);
    generarEnemigo(nivel, sdlRenderer, mapa, posicionDeEscenario);
    generarTransicion(nivel, sdlRenderer, mapa, posicionDeJugador);
}

Entidad * Nivel::generarEscenario(const string &nivel, SDL_Renderer *sdlRenderer, Mapa *mapa) {
    /**
     * Leer configuracion de escenario.
     */
    Locator::logger()->log(DEBUG, "Se genera escenario para " + nivel);

    Configuracion *config = Locator::configuracion();
    string srcSprite = config->getValue("/niveles/" + nivel + "/escenario/sprite/src");
    int profundidad = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");
    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    int cantidadDeCapas = config->getIntValue("/niveles/" + nivel + "/escenario/sprite/capas/cantidad");

    Locator::logger()->log(DEBUG, "Se cargo profundidad para escenario: " + to_string(profundidad));
    Locator::logger()->log(DEBUG, "Se cargo ancho para escenario: " + to_string(anchoNivel));
    Locator::logger()->log(DEBUG, "Se cargo cantidad de capas para escenario: " + to_string(cantidadDeCapas));

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
        float distanciaAlFondo = config->getFloatValue(
                "/niveles/" + nivel + "/escenario/sprite/capas/capa" + to_string(i) + "/distanciaAlFondo");

        Locator::logger()->log(DEBUG, "Se obtiene eje x para capa " + to_string(i+1) + ": " + to_string(x));
        Locator::logger()->log(DEBUG, "Se obtiene eje y para capa " + to_string(i+1) + ": " + to_string(y));
        Locator::logger()->log(DEBUG, "Se obtiene alto para capa " + to_string(i+1) + ": " + to_string(alto));
        Locator::logger()->log(DEBUG, "Se obtiene distancia al fondo para capa " + to_string(i+1) + ": " + to_string(distanciaAlFondo));

        sprites[i] = sprite->getTexture();
        posicionesSprite[i] = {x, y, 0, alto};
        distanciasAlFondo[i] = distanciaAlFondo;
    }

    float escalaHorizontal = (float)anchoNivel / (float)sprite->ancho();
    auto *grafico = new GraficoDeEscenario(sprites, posicionesSprite, distanciasAlFondo, escalaHorizontal);

    escenario->agregarEstado("posicion", posicion);
    escenario->agregarEstado("sprite", sprite);
    escenario->agregarEstado("mapa", mapa);
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

    Configuracion *config = Locator::configuracion();
    int cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/enemigos/cantidad");
    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    int profundidadNivel = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");
    string spritePath = config->getValue("/niveles/" + nivel + "/escenario/enemigos/sprite/src");

    for (int i = 0; i < cantidad; i++) {
        Locator::logger()->log(INFO, "Se genera enemigo");

        Entidad *enemigo = mapa->crearEntidad();

        auto *posicionEnemigoRandom = new Posicion(generarPosicionX(anchoNivel), generarPosicionY(profundidadNivel), 0);
        auto *spriteEnemigo = new Sprite(sdlRenderer, spritePath);
        auto *velocidadDeEnemigo = new Velocidad();
        auto *fabricaDeEnemigo = new FabricaDeAnimacionesDePoison();
        auto *animacion = fabricaDeEnemigo->caminando();
        auto *orientacionDeEnemigo = new Orientacion;
        auto *comportadmiento = new Patrullar();
        auto *fisicaDeEnemigo = new FisicaDePersonaje();
        auto *graficoDeEnemigo = new Grafico();
        EstadoDePersonaje *estado = new Caminando();

        enemigo->agregarEstado("estado", estado);
        enemigo->agregarEstado("posicion", posicionEnemigoRandom);
        enemigo->agregarEstado("sprite", spriteEnemigo);
        enemigo->agregarEstado("velocidad", velocidadDeEnemigo);
        enemigo->agregarEstado("fabrica de animaciones", fabricaDeEnemigo);
        enemigo->agregarEstado("animacion", animacion);
        enemigo->agregarEstado("posicion de escenario", posicionDeEscenario);
        enemigo->agregarEstado("orientacion", orientacionDeEnemigo);
        enemigo->agregarComportamiento("comportamiento", comportadmiento);
        enemigo->agregarComportamiento("fisica", fisicaDeEnemigo);
        enemigo->agregarComportamiento("grafico", graficoDeEnemigo);
    }
}

void Nivel::generarTransicion(const string &nivel, SDL_Renderer *sdlRenderer, Mapa *mapa, Posicion* posicionDeJugador) {
    Locator::logger()->log(DEBUG, "Se genera transicion");

    Entidad *transicion = mapa->crearEntidad();
    int anchoDeNivel = Locator::configuracion()->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    auto *posicion = new Posicion(0, 1, 0);
    auto *grafico = new GraficoDeTransicion(anchoDeNivel);

    transicion->agregarEstado("posicion", posicion);
    transicion->agregarEstado("posicion de jugador", posicionDeJugador);
    transicion->agregarComportamiento("grafico", grafico);
}
