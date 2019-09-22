//
// Created by felipe on 22/9/19.
//



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

Nivel::Nivel() {

}

int generarPosicionX(int limiteDeFrontera){
    return rand() % limiteDeFrontera;
}

int generarPosicionY(){
    return rand() % 400;
}

void Nivel::generarNivel(SDL_Renderer *sdlRenderer, Mapa *mapa, int cantidadDeCajas, int cantidadCuchillos) {

    /**
        * Crear jugador.
        */
    Entidad * jugador = mapa->crearEntidad();

    auto * posicionDeJugador = new Posicion(200, 100, 0);
    jugador->agregarEstado("posicion", posicionDeJugador);

    auto * velocidadDeJugador = new Velocidad();
    jugador->agregarEstado("velocidad", velocidadDeJugador);

    auto * spriteJugador = new Sprite(sdlRenderer, "assets/personajes/cody.png");
    jugador->agregarEstado("sprite", spriteJugador);

    auto *orientacionDeJugador = new Orientacion;
    jugador->agregarEstado("orientacion", orientacionDeJugador);

    auto *animacionDeJugador = FabricaDeAnimacionesDeCody::parado();
    jugador->agregarEstado("animacion", animacionDeJugador);

    EstadoDePersonaje * estadoDeJugador = new Parado();
    jugador->agregarComportamiento("estado", estadoDeJugador);

    auto * fisicaDeJugador = new FisicaDePersonaje();
    jugador->agregarComportamiento("fisica", fisicaDeJugador);

    auto * graficoDeJugador = new Grafico();
    jugador->agregarComportamiento("grafico", graficoDeJugador);

    /**
        * Crear escenario.
        */
    Entidad * escenario = mapa->crearEntidad();

    auto * posicionDeEscenario = new Posicion(0, 300, 0);
    escenario->agregarEstado("posicion", posicionDeEscenario);

    auto * spriteEscenario = new Sprite(sdlRenderer, "assets/escenarios/nivel1.png");
    escenario->agregarEstado("sprite", spriteEscenario);

    auto * fisicaEscenario = new FisicaDeEscenario();
    escenario->agregarComportamiento("fisica", fisicaEscenario);

    vector<SDL_Texture *> spritesDeEscenario;
    spritesDeEscenario.push_back(spriteEscenario->getTexture());
    spritesDeEscenario.push_back(spriteEscenario->getTexture());
    spritesDeEscenario.push_back(spriteEscenario->getTexture());

    vector<SDL_Rect> posicionesSprite;
    posicionesSprite.push_back({0, 400, 0, 400});
    posicionesSprite.push_back({0, 200, 0, 195});
    posicionesSprite.push_back({0, 0, 0, 195});

    vector<float> distanciasAlFondo = {0.1, 0.5, 1};

    auto* graficoDeEscenario = new GraficoDeEscenario(spritesDeEscenario, posicionesSprite, distanciasAlFondo,
                                                      spriteEscenario->ancho());
    escenario->agregarComportamiento("grafico", graficoDeEscenario);

    /**
     * Dependencias.
     */
    escenario->agregarEstado("posicion de jugador", posicionDeJugador);
    jugador->agregarEstado("posicion de escenario", posicionDeEscenario);

    //Agregamos cajas random
    auto * spriteCaja = new Sprite(sdlRenderer, "assets/escenarios/caja.png");
    Animacion* animacionCaja = FabricaDeAnimacionesDeCaja::standby();

    for (int i = 1; i <= cantidadDeCajas; i++) {
        Locator::logger()->log(INFO,"Se inicia la construccion de la cajaRandom:" + to_string(i));

        Entidad* cajaRandom = mapa->crearEntidad();

        auto* posicionCajaRandom = new Posicion(generarPosicionX(spriteEscenario->ancho()), generarPosicionY(), 0);
        auto * graficoDeCaja = new Grafico();
        cajaRandom->agregarEstado("posicion", posicionCajaRandom);
        cajaRandom->agregarEstado("sprite", spriteCaja);
        cajaRandom->agregarEstado("animacion", animacionCaja);
        cajaRandom->agregarEstado("posicion de escenario", posicionDeEscenario);
        cajaRandom->agregarComportamiento("grafico", graficoDeCaja);
    }

    auto * spriteCuchillo = new Sprite(sdlRenderer, "assets/objetos/cuchillo.png");
    Animacion* animacionCuchillo = FabricaDeAnimacionesDeCuchillo::standby();

    for (int i = 1; i <= cantidadCuchillos; i++) {
        Locator::logger()->log(INFO,"Se inicia la construccion de la cuchilloRandom:" + to_string(i));

        Entidad* cuchilloRandom = mapa->crearEntidad();

        auto* posicionCuchilloRandom = new Posicion(generarPosicionX(spriteEscenario->ancho()), generarPosicionY(), 0);

        auto * graficoDeCuchillo = new Grafico();
        cuchilloRandom->agregarEstado("posicion", posicionCuchilloRandom);
        cuchilloRandom->agregarEstado("sprite", spriteCuchillo);
        cuchilloRandom->agregarEstado("animacion", animacionCuchillo);
        cuchilloRandom->agregarEstado("posicion de escenario", posicionDeEscenario);
        cuchilloRandom->agregarComportamiento("grafico", graficoDeCuchillo);
    }

 //
    Entidad * enemigo = mapa->crearEntidad();

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