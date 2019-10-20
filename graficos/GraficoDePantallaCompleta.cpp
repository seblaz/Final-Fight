//
// Created by sebas on 3/10/19.
//

#include "GraficoDePantallaCompleta.h"
#include "Sprite.h"
#include "../servicios/Locator.h"
#include "../modelo/Personaje.h"
#include "animaciones/Animacion.h"


SDL_Rect calcularPosicionEnPantalla2(Posicion posicionEnMapa, SDL_Rect posicionEnSprite, float esacalaDeAnimacion) {
    Configuracion *config = Locator::configuracion();

    float escala = config->getFloatValue("/escala/entidades") * esacalaDeAnimacion;

    const int screenX = int(round((float) posicionEnMapa.getX()
                                  - (float) posicionEnSprite.w / 2 * escala));

    const int screenY = int(round((float) config->getIntValue("/resolucion/alto")
                                  - (float) posicionEnMapa.getZ()
                                  - (float) posicionEnMapa.getY()
                                  - (float) posicionEnSprite.h * escala));

    SDL_Rect posicionEnPantalla = {screenX,
                                   screenY,
                                   int((float) posicionEnSprite.w * escala),
                                   int((float) posicionEnSprite.h * escala)};

    return posicionEnPantalla;
}

void GraficoDePantallaCompleta::actualizar(Entidad *entidad) {
    auto *sprite = entidad->getEstado<Sprite>("sprite");
    auto *personajeMarcado = entidad->getEstado<Personaje>("personajeMarcado");
    auto *renderer = Locator::renderer();
    SDL_RenderCopy(renderer, sprite->getTexture(), nullptr, nullptr);
    if (personajeMarcado != nullptr) {

        auto *animacionIndicador = entidad->getEstado<Animacion>("indicador");
        auto *spriteIndicador = entidad->getEstado<Sprite>("selector");

        SDL_Rect posicionEnSpriteIndicador = animacionIndicador->actualizarYDevolverPosicion();

        switch (personajeMarcado->getPersonaje()) {
            case GUY: {
                Posicion nuevaPosicionIndicador(300, 450, 100);
                SDL_Rect posicionEnPantallaIndicador = calcularPosicionEnPantalla2(nuevaPosicionIndicador,
                                                                                   posicionEnSpriteIndicador,
                                                                                   animacionIndicador->escala());
                SDL_RenderCopy(renderer, spriteIndicador->getTexture(), &posicionEnSpriteIndicador,
                               &posicionEnPantallaIndicador);
            }
                break;
            case CODY: {
                Posicion nuevaPosicionIndicador(500, 450, 100);
                SDL_Rect posicionEnPantallaIndicador = calcularPosicionEnPantalla2(nuevaPosicionIndicador,
                                                                                   posicionEnSpriteIndicador,
                                                                                   animacionIndicador->escala());
                SDL_RenderCopy(renderer, spriteIndicador->getTexture(), &posicionEnSpriteIndicador,
                               &posicionEnPantallaIndicador);
            }
                break;
            case HAGGAR: {
                Posicion nuevaPosicionIndicador(700, 450, 100);
                SDL_Rect posicionEnPantallaIndicador = calcularPosicionEnPantalla2(nuevaPosicionIndicador,
                                                                                   posicionEnSpriteIndicador,
                                                                                   animacionIndicador->escala());
                SDL_RenderCopy(renderer, spriteIndicador->getTexture(), &posicionEnSpriteIndicador,
                               &posicionEnPantallaIndicador);
            }
                break;
            case MAKI: {
                Posicion nuevaPosicionIndicador(900, 450, 100);
                SDL_Rect posicionEnPantallaIndicador = calcularPosicionEnPantalla2(nuevaPosicionIndicador,
                                                                                   posicionEnSpriteIndicador,
                                                                                   animacionIndicador->escala());
                SDL_RenderCopy(renderer, spriteIndicador->getTexture(), &posicionEnSpriteIndicador,
                               &posicionEnPantallaIndicador);
            }
                break;
        }
    }
}
