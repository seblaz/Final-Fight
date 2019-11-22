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
#include "../modelo/serializables/EstadoDePersonaje.h"
#include "../modelo/serializables/Actividad.h"
#include "../modelo/serializables/Puntaje.h"

GraficoJugador::GraficoJugador(Entidad *entidad) : Grafico(entidad) {}

void GraficoJugador::actualizar() {

    auto *puntaje = entidad->getEstado<Puntaje>("puntaje");
    auto *numeroJugador = entidad->getEstado<NumeroJugador>("numeroJugador");

    modularColor();

    Grafico::actualizar();
    renderizarIndicadorDeJugador();
    renderizarVidaDeJugador();
    renderizarPuntosDeJugador(puntaje, numeroJugador);
}

void GraficoJugador::renderizarIndicadorDeJugador() {
    SDL_Renderer *renderer = Locator::renderer();
    int posicionDeEscenarioX = Locator::posicionEscenario()->x;
    auto *posicion = entidad->getEstado<Posicion>("posicion");
    auto *spriteIndicador = entidad->getEstado<Sprite>("spriteIndicador");
    auto *numeroJugador = entidad->getEstado<NumeroJugador>("numeroJugador");

    Posicion nuevaPosicion(posicion->getX() - posicionDeEscenarioX, posicion->getY(), posicion->getZ());
    SDL_Rect posicionEnSpriteIndicador = {0, 0, 45, 45};
    Posicion nuevaPosicionIndicador(posicion->getX() - posicionDeEscenarioX, posicion->getY(), posicion->getZ() + 450);
    SDL_Rect posicionEnPantallaIndicador = calcularPosicionEnPantalla(nuevaPosicionIndicador, posicionEnSpriteIndicador,
                                                                      1.5);
    SDL_RenderCopy(renderer, spriteIndicador->getTexture(), &posicionEnSpriteIndicador, &posicionEnPantallaIndicador);


    SDL_Rect rect = {5 + (numeroJugador->numeroJugador - 1) * 350, 40, 20, 50};

    switch (numeroJugador->numeroJugador) {
        case 1:
            SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            break;
        case 2:
            SDL_SetRenderDrawColor(renderer, 245, 255, 0, 255);
            break;
        case 3:
            SDL_SetRenderDrawColor(renderer, 0, 194, 70, 255);
            break;
        case 4:
            SDL_SetRenderDrawColor(renderer, 91, 0, 208, 255);
            break;
    };

    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderDrawRect(renderer, &rect);

}


void GraficoJugador::renderizarVidaDeJugador() {

    SDL_Renderer *renderer = Locator::renderer();
    auto *spriteVida = entidad->getEstado<Sprite>("sprite vida");
    auto *spriteVidaActual = entidad->getEstado<Sprite>("sprite vida actual");
    auto *spriteCorazon = entidad->getEstado<Sprite>("sprite cantidad de vidas");

    auto *energia = entidad->getEstado<Energia>("energia");
    auto *numeroJugador = entidad->getEstado<NumeroJugador>("numeroJugador");


    SDL_Rect posicionEnSpriteVidaLlena = {0, 0, 95, 17};
    SDL_Rect posicionEnPantallaVidaLlena = {30 + (numeroJugador->numeroJugador - 1) * 350, 40, 95 * escalaVida,
                                            17 * escalaVida};

    SDL_RenderCopy(renderer, spriteVida->getTexture(), &posicionEnSpriteVidaLlena, &posicionEnPantallaVidaLlena);

    SDL_Rect posicionEnSpriteVidaActual = {0, 0, (82 * energia->getEnergia() / 100), 9};
    SDL_Rect posicionEnPantallaVidaActual = {69 + (numeroJugador->numeroJugador - 1) * 350, 64,
                                             (82 * energia->getEnergia() / 100) * escalaVida, 9 * escalaVida};
    SDL_RenderCopy(renderer, spriteVidaActual->getTexture(), &posicionEnSpriteVidaActual,
                   &posicionEnPantallaVidaActual);

    int cantidadDeVidasActuales = energia->getVidas();
    SDL_Rect posicionEnSpriteCorazon = {0, 0, 11, 11};
    for (int i = 0; i < cantidadDeVidasActuales; i++) {
        SDL_Rect posicionEnPantallaCorazon = {230 + (i * 26) + (numeroJugador->numeroJugador - 1) * 350, 40, 11 * 2,
                                              11 * 2};
        SDL_RenderCopy(renderer, spriteCorazon->getTexture(), &posicionEnSpriteCorazon, &posicionEnPantallaCorazon);
    }
}

void GraficoJugador::renderizarPuntosDeJugador(Puntaje *puntaje, NumeroJugador* numeroJugador) {
    SDL_Renderer *renderer = Locator::renderer();

    string puntos = to_string(puntaje->obtenerPuntos());

    int cantidadDigitos = puntos.length();

    SDL_Color colorDeFuente = {0, 0, 0};
    SDL_Surface *surfacePuntos = TTF_RenderText_Solid(Locator::fuente(),
                                                      puntos.c_str(), colorDeFuente);
    SDL_Texture *texturaPuntos = SDL_CreateTextureFromSurface(renderer, surfacePuntos);
    SDL_FreeSurface(surfacePuntos);

    SDL_Rect posicionPuntos = {30 + (numeroJugador->numeroJugador - 1) * 350, 0, 30 * cantidadDigitos, 50};
    SDL_RenderCopy(renderer, texturaPuntos, nullptr, &posicionPuntos);
    SDL_DestroyTexture(texturaPuntos);
}

void GraficoJugador::modularColor() {
    auto *sprite = entidad->getEstado<Sprite>("sprite");
    auto *actividad = entidad->getEstado<Actividad>("actividad");
    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado de personaje");
    auto *energia = entidad->getEstado<Energia>("energia");

    if ((actividad != nullptr)) {
        if (!actividad->activo) {
            SDL_SetTextureColorMod(sprite->getTexture(), 100, 100, 100);
        } else {
            SDL_SetTextureColorMod(sprite->getTexture(), 255, 255, 255);
        }
    }

    if (estado->getEstado() == MUERTO && energia->vivo()) {
        int mod = claro * 255 + !claro * 64;
        SDL_SetTextureColorMod(sprite->getTexture(), mod, mod, mod);
        if (framesModulacion-- == 0) {
            framesModulacion = 8;
            claro = !claro;
        }
    }
}
