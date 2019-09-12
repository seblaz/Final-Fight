//
// Created by sebas on102/9/19.
//

#include "GraficoDePersonajeCaminando.h"
#include "../modelo/mapeables/Personaje.h"
#include "../servicios/Locator.h"
#include <cmath>

GraficoDePersonajeCaminando::GraficoDePersonajeCaminando(SDL_Renderer *renderer, SDL_Texture *texturaSprite) :
        renderer(renderer),
        texture(texturaSprite),
        spriteActual(0),
        cantidadDeSprites(6),
        coordenadasSprites{
                {10,  100, 29, 90},
                {51,  100, 47, 90},
                {113, 100, 43, 90},
                {164, 100, 27, 90},
                {212, 100, 47, 90},
                {266, 100, 47, 90},
        },
        framesFaltantes(10) {}

void GraficoDePersonajeCaminando::actualizar(Mapeable &mapeable) {
    auto &personaje = dynamic_cast<Personaje &>(mapeable);

    Configuracion *config = Locator::configuracion();
    Posicion &posicion = personaje.posicion(); // Se obtiene la posicion del jugador y en base a eso se construye el hitbox del jugador.

    const int screenX = posicion.getX()
                        + posicion.getY() * cos(config->inclinacionDeEscenario)
                        - coordenadasSprites[spriteActual].w / 2 * config->escalaDeGraficos;
    const int screenY = config->alturaDePantalla
                        + posicion.getZ()
                        - posicion.getY() * cos(M_PI / 2 - config->inclinacionDeEscenario)
                        - coordenadasSprites[spriteActual].h * config->escalaDeGraficos;

    SDL_Rect posicionJugador = {screenX,
                                screenY,
                                int(coordenadasSprites[spriteActual].w * config->escalaDeGraficos),
                                int(coordenadasSprites[spriteActual].h * config->escalaDeGraficos)};

    //Se renderiza en la ventana la imagen, la posicion del sprite, y la posicion del jugador
    SDL_RenderCopy(renderer, texture, &coordenadasSprites[spriteActual], &posicionJugador);
    framesFaltantes--;
    if (framesFaltantes <= 0) {
        framesFaltantes = 10;
        spriteActual = (spriteActual + 1) % cantidadDeSprites;
    }
}

