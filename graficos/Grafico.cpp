#include <SDL_rect.h>
#include "../modelo/Posicion.h"
#include "../servicios/Locator.h"

SDL_Rect calcularPosicionEnPantalla(Posicion posicionEnMapa, SDL_Rect posicionEnSprite, float esacalaDeAnimacion){
    Configuracion *config = Locator::configuracion();

    float escala = config->escalaDeGraficos * esacalaDeAnimacion;

    const int screenX = posicionEnMapa.getX()
                        + posicionEnMapa.getY() * cos(config->inclinacionDeEscenario)
                        - posicionEnSprite.w / 2 * escala;

    const int screenY = config->alturaDePantalla
                        + posicionEnMapa.getZ()
                        - posicionEnMapa.getY() * cos(M_PI / 2 - config->inclinacionDeEscenario)
                        - posicionEnSprite.h * escala;

    SDL_Rect posicionEnPantalla = {screenX,
                                screenY,
                                int(posicionEnSprite.w * escala),
                                int(posicionEnSprite.h * escala)};

    return posicionEnPantalla;
}
