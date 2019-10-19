//
// Created by sebas on 21/9/19.
//

#include <SDL_rect.h>
#include "Grafico.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"
#include "animaciones/Animacion.h"
#include "Sprite.h"
#include "../modelo/Orientacion.h"
#include "../modelo/Actividad.h"
#include "../modelo/Personaje.h"

SDL_Rect calcularPosicionEnPantalla(Posicion posicionEnMapa, SDL_Rect posicionEnSprite, float esacalaDeAnimacion) {
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

void Grafico::actualizar(Entidad *entidad) {
    auto *posicion = entidad->getEstado<Posicion>("posicion");
    int posicionDeEscenarioX = Locator::posicionEscenario()->x;
    int dif = posicion->x - posicionDeEscenarioX;

    if (dif > -200 && dif < Locator::configuracion()->getIntValue("/resolucion/ancho") + 200) {
        SDL_Renderer *renderer = Locator::renderer();
        auto *animacion = entidad->getEstado<Animacion>("animacion");
        auto *sprite = entidad->getEstado<Sprite>("sprite");
        auto *orientacion = entidad->getEstado<Orientacion>("orientacion");
        auto *actividad = entidad->getEstado<Actividad>("actividad");

        auto *personaje = entidad->getEstado<Personaje>("personaje");


        Posicion nuevaPosicion(posicion->getX() - posicionDeEscenarioX, posicion->getY(), posicion->getZ());
        SDL_Rect posicionEnSprite = animacion->actualizarYDevolverPosicion();
        SDL_Rect posicionEnPantalla = calcularPosicionEnPantalla(nuevaPosicion, posicionEnSprite, animacion->escala());

        if ((actividad != nullptr)) {
            if (!actividad->activo) {
                SDL_SetTextureColorMod(sprite->getTexture(), 100, 100, 100);
            } else {
                SDL_SetTextureColorMod(sprite->getTexture(), 255, 255, 255);
            }
        }

        if (personaje != nullptr){
            auto *animacionIndicador = entidad->getEstado<Animacion>("animacionIndicador");
            auto *spriteIndicador = entidad->getEstado<Sprite>("spriteIndicador");

            SDL_Rect posicionEnSpriteIndicador = animacionIndicador->actualizarYDevolverPosicion();
            Posicion nuevaPosicionIndicador(posicion->getX() - posicionDeEscenarioX, posicion->getY()+450, posicion->getZ());
            SDL_Rect posicionEnPantallaIndicador = calcularPosicionEnPantalla(nuevaPosicionIndicador, posicionEnSpriteIndicador, animacionIndicador->escala());

            SDL_RenderCopy(renderer, spriteIndicador->getTexture(), &posicionEnSpriteIndicador, &posicionEnPantallaIndicador);

            //SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);

            //SDL_RenderDrawLine(renderer, nuevaPosicion.getX() , -nuevaPosicion.getY() + 380 *2,nuevaPosicion.getX()+40 *2 ,-nuevaPosicion.getY() + 380 *2);
            //SDL_RenderDrawLine(renderer, nuevaPosicion.getX() + 20, -nuevaPosicion.getY() + 420 *2,nuevaPosicion.getX()+40 *2 ,-nuevaPosicion.getY() + 380 *2);
            //SDL_RenderDrawLine(renderer, nuevaPosicion.getX() , -nuevaPosicion.getY() + 380 *2,nuevaPosicion.getX()+20 *2 ,-nuevaPosicion.getY() + 420 *2);
        }

        if ((orientacion != nullptr) && (!orientacion->adelante)) {
            SDL_RenderCopyEx(renderer, sprite->getTexture(), &posicionEnSprite, &posicionEnPantalla,
                             180, nullptr, SDL_FLIP_VERTICAL);
        } else {
            SDL_RenderCopy(renderer, sprite->getTexture(), &posicionEnSprite, &posicionEnPantalla);
        }
    }
}

