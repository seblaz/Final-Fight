//
// Created by sebas on 21/9/19.
//

#include <SDL_rect.h>
#include "Grafico.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"
#include "Animacion.h"
#include "Sprite.h"
#include "../modelo/Orientacion.h"

SDL_Rect calcularPosicionEnPantalla2(Posicion posicionEnMapa, SDL_Rect posicionEnSprite, float esacalaDeAnimacion) {
    Configuracion *config = Locator::configuracion();

    float escala = config->getFloatValue("/escala/mapeables") * esacalaDeAnimacion;

    const int screenX = posicionEnMapa.getX()
                        - posicionEnSprite.w / 2 * escala;

    const int screenY = config->getIntValue("/resolucion/alto")
                        + posicionEnMapa.getZ()
                        - posicionEnMapa.getY()
                        - posicionEnSprite.h * escala;

    SDL_Rect posicionEnPantalla = {screenX,
                                   screenY,
                                   int(posicionEnSprite.w * escala),
                                   int(posicionEnSprite.h * escala)};

    return posicionEnPantalla;
}

void Grafico::actualizar(Entidad *entidad) {
    SDL_Renderer *renderer = Locator::renderer();
    auto *posicion = entidad->getEstado<Posicion>("posicion");
    int posicionDeEscenarioX = entidad->getEstado<Posicion>("posicion de escenario")->getX();
    auto *animacion = entidad->getEstado<Animacion>("animacion");
    auto *sprite = entidad->getEstado<Sprite>("sprite");
    auto *orientacion = entidad->getEstado<Orientacion>("orientacion");

    Posicion nuevaPosicion(posicion->getX() - posicionDeEscenarioX, posicion->getY(), posicion->getZ());
    SDL_Rect posicionEnSprite = animacion->actualizarYDevolverPosicion();
    SDL_Rect posicionEnPantalla = calcularPosicionEnPantalla2(nuevaPosicion, posicionEnSprite, animacion->escala());

    if ((orientacion != nullptr) && (!orientacion->adelante)) {
        SDL_RenderCopyEx(renderer, sprite->getTexture(), &posicionEnSprite, &posicionEnPantalla,
                         180, nullptr, SDL_FLIP_VERTICAL);
    } else {
        SDL_RenderCopy(renderer, sprite->getTexture(), &posicionEnSprite, &posicionEnPantalla);
    }
}
