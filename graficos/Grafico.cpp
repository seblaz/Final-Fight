//
// Created by sebas on 21/9/19.
//

#include <SDL_rect.h>
#include "Grafico.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"
#include "Animacion.h"
#include "sprite/Sprite.h"

SDL_Rect calcularPosicionEnPantalla2(Posicion posicionEnMapa, SDL_Rect posicionEnSprite, float esacalaDeAnimacion){
    Configuracion *config = Locator::configuracion();

    float escala = config->getFloatValue("/escala/mapeables") * esacalaDeAnimacion;

    const int screenX = posicionEnMapa.getX()
                        + posicionEnMapa.getY() * cos(config->getFloatValue("/escenario/inclinacion"))
                        - posicionEnSprite.w / 2 * escala;

    const int screenY = config->getIntValue("/resolucion/alto")
                        + posicionEnMapa.getZ()
                        - posicionEnMapa.getY() * cos(M_PI / 2 - config->getFloatValue("/escenario/inclinacion"))
                        - posicionEnSprite.h * escala;

    SDL_Rect posicionEnPantalla = {screenX,
                                screenY,
                                int(posicionEnSprite.w * escala),
                                int(posicionEnSprite.h * escala)};

    return posicionEnPantalla;
}

void Grafico::actualizar(Entidad *entidad) {
    SDL_Renderer *renderer = Locator::renderer();
    auto* posicion = entidad->getEstado<Posicion>();
    auto *animacion = entidad->getEstado<Animacion>();
    auto *sprite = entidad->getEstado<Sprite>();
//    Posicion nuevaPosicion(posicion->getX() - fisicaDeEscenario.posicion(), fisica->posicion().getY(),
//                           fisica->posicion().getZ());
    SDL_Rect posicionEnSprite = animacion->actualizarYDevolverPosicion();
    SDL_Rect posicionEnPantalla = calcularPosicionEnPantalla2(*posicion, posicionEnSprite, animacion->escala());

    SDL_RenderCopy(renderer, sprite->getTexture(), &posicionEnSprite, &posicionEnPantalla);
}
