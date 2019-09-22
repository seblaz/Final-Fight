//
// Created by felipe on 22/9/19.
//



#include "Nivel.h"
#include "../modelo/Posicion.h"
#include "../graficos/Sprite.h"
#include "../modelo/Orientacion.h"
#include "../estados/Parado.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../graficos/Grafico.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../graficos/GraficoDeEscenario.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"

Nivel::Nivel() {


}

void Nivel::generarNivel(SDL_Renderer *sdlRenderer, Mapa *mapa) {

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


}