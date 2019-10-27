//
// Created by sebas on 21/10/19.
//

#include "GraficoJugador.h"
#include "Grafico.h"
#include "animaciones/AnimacionCliente.h"
#include "Sprite.h"
#include "../modelo/Posicion.h"
#include "../servicios/Locator.h"

void GraficoJugador::actualizar(Entidad *jugador) {
    Grafico::actualizar(jugador);
    SDL_Renderer *renderer = Locator::renderer();
    int posicionDeEscenarioX = Locator::posicionEscenario()->x;
    auto *posicion = jugador->getEstado<Posicion>("posicion");
    auto *spriteIndicador = jugador->getEstado<Sprite>("spriteIndicador");

    auto *animacion = jugador->getEstado<AnimacionCliente>("animacion");

    Posicion nuevaPosicion(posicion->getX() - posicionDeEscenarioX, posicion->getY(), posicion->getZ());
    SDL_Rect posicionEnSprite = animacion->devolverPosicion(jugador);
    SDL_Rect posicionEnPantalla = calcularPosicionEnPantalla(nuevaPosicion, posicionEnSprite, animacion->escala());

    SDL_Rect posicionEnSpriteIndicador = {0, 0, 45, 45};
    Posicion nuevaPosicionIndicador(posicion->getX() - posicionDeEscenarioX, posicion->getY(), posicion->getZ() + posicionEnPantalla.h);
    SDL_Rect posicionEnPantallaIndicador = calcularPosicionEnPantalla(nuevaPosicionIndicador, posicionEnSpriteIndicador,
                                                                      1.5);

    SDL_RenderCopy(renderer, spriteIndicador->getTexture(), &posicionEnSpriteIndicador, &posicionEnPantallaIndicador);
}