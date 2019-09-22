//
// Created by sebas on 18/9/19.
//

#include "Nivel1.h"
#include "../comportamiento/ComportamientoNulo.h"

Nivel1::Nivel1() {
//    Mapeable *jugador = mapa.jugador();
//    mapa.vaciarMapa();
//
//    Mapeable *escenario = generarEscenario(renderer, dynamic_cast<FisicaDePersonaje *>(jugador->fisica()));
//    mapa.agregar(escenario);
//    mapa.agregarJugador(jugador);
}

Mapeable *Nivel1::generarEscenario(SDL_Renderer *renderer, FisicaDePersonaje *fisicaDeJugador) {
    // Animacion.
    auto* spriteEscenario = new Sprite(renderer, "assets/escenarios/nivel1.png");

    vector<SDL_Texture *> spritesDeEscenario;
    spritesDeEscenario.push_back(spriteEscenario->getTexture());
    spritesDeEscenario.push_back(spriteEscenario->getTexture());
    spritesDeEscenario.push_back(spriteEscenario->getTexture());

    vector<SDL_Rect> posicionesSprite;
    posicionesSprite.push_back({0, 400, 0, 400});
    posicionesSprite.push_back({0, 200, 0, 195});
    posicionesSprite.push_back({0, 0, 0, 195});

    // Fisica.
    int ancho = Locator::configuracion()->getIntValue("/escala/escenario/ancho");
    auto *fisicaDeEscenario = new FisicaDeEscenario(fisicaDeJugador, ancho * spriteEscenario->ancho());

    //


    // Grafico.
    vector<float> distanciasAlFondo = {0.1, 0.5, 1};
    auto *graficoDeEscenario = new GraficoDeEscenario(*fisicaDeEscenario, spritesDeEscenario, posicionesSprite, distanciasAlFondo,
                                          spriteEscenario->ancho());
    auto* comportamientoDeEscenario = new ComportamientoNulo();
    return new Mapeable(fisicaDeEscenario, graficoDeEscenario, comportamientoDeEscenario);
}
