//
// Created by sebas on 12/9/19.
//

#include "GraficoDePersonajeSaltando.h"
#include "../modelo/mapeables/Personaje.h"
#include "../servicios/Configuracion.h"
#include "../servicios/Locator.h"

GraficoDePersonajeSaltando::GraficoDePersonajeSaltando(SDL_Renderer *renderer, SDL_Texture *texturaSprite) :
        renderer(renderer),
        texture(texturaSprite),
        spriteActual(0),
        cantidadDeSprites(4),
        coordenadasSprites{
                {16,  238, 39, 81},
                {74,  203, 32, 106},
                {177, 220, 53, 83},
                {115, 218, 47, 74},
        },
        framesFaltantes(20) {}

void GraficoDePersonajeSaltando::actualizar(Mapeable &mapeable) {
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
        framesFaltantes = 20;
        spriteActual = (spriteActual + 1) % cantidadDeSprites;
    }
}
