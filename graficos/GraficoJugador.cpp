//
// Created by sebas on 21/10/19.
//

#include "GraficoJugador.h"
#include "Grafico.h"
#include "AnimacionCliente.h"
#include "Sprite.h"
#include "../modelo/serializables/Posicion.h"
#include "../servicios/Locator.h"
#include "../modelo/serializables/Energia.h"
#include "../modelo/serializables/NumeroJugador.h"

GraficoJugador::GraficoJugador(Entidad *entidad) : Grafico(entidad) {}

void GraficoJugador::actualizar() {
    Grafico::actualizar();
    SDL_Renderer *renderer = Locator::renderer();
    int posicionDeEscenarioX = Locator::posicionEscenario()->x;
    auto *posicion = entidad->getEstado<Posicion>("posicion");
    auto *spriteIndicador = entidad->getEstado<Sprite>("spriteIndicador");

    auto *animacion = entidad->getEstado<AnimacionCliente>("animacion");

    Posicion nuevaPosicion(posicion->getX() - posicionDeEscenarioX, posicion->getY(), posicion->getZ());
    SDL_Rect posicionEnSprite = animacion->devolverPosicion(entidad);
    SDL_Rect posicionEnPantalla = calcularPosicionEnPantalla(nuevaPosicion, posicionEnSprite, animacion->escala());

    SDL_Rect posicionEnSpriteIndicador = {0, 0, 45, 45};
    Posicion nuevaPosicionIndicador(posicion->getX() - posicionDeEscenarioX, posicion->getY(),
                                    posicion->getZ() + posicionEnPantalla.h);
    SDL_Rect posicionEnPantallaIndicador = calcularPosicionEnPantalla(nuevaPosicionIndicador, posicionEnSpriteIndicador,
                                                                      1.5);
    SDL_RenderCopy(renderer, spriteIndicador->getTexture(), &posicionEnSpriteIndicador, &posicionEnPantallaIndicador);

    renderizarVidaDeJugador();
}

void GraficoJugador::renderizarVidaDeJugador() {

    SDL_Renderer *renderer = Locator::renderer();
    auto *spriteVida = entidad->getEstado<Sprite>("sprite vida");
    auto *spriteVidaActual = entidad->getEstado<Sprite>("sprite vida actual");
    auto *energia = entidad->getEstado<Energia>("energia");
    auto *numeroJugador = entidad->getEstado<NumeroJugador>("numeroJugador");

    SDL_Rect posicionEnSpriteVidaLlena = {0, 0, 95, 17};
    SDL_Rect posicionEnPantallaVidaLlena = {20 + (numeroJugador->numeroJugador - 1  ) * 350 , 40, 95 * escalaVida, 17 * escalaVida};

    SDL_RenderCopy(renderer, spriteVida->getTexture(), &posicionEnSpriteVidaLlena, &posicionEnPantallaVidaLlena);

    SDL_Rect posicionEnSpriteVidaActual = {0, 0, (82 * energia->getEnergia() / 100) , 9};
    SDL_Rect posicionEnPantallaVidaActual = {59 + (numeroJugador->numeroJugador - 1 ) * 350, 64, (82 * energia->getEnergia() / 100)  * escalaVida, 9* escalaVida};

    SDL_RenderCopy(renderer, spriteVidaActual->getTexture(), &posicionEnSpriteVidaActual, &posicionEnPantallaVidaActual);
}
