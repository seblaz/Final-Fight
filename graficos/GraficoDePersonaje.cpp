//
// Created by sebas on 13/9/19.
//

#include "GraficoDePersonaje.h"
#include "../modelo/mapeables/Personaje.h"
#include "../servicios/Configuracion.h"
#include "../servicios/Locator.h"

#include <utility>

GraficoDePersonaje::GraficoDePersonaje(SDL_Renderer *renderer, SDL_Texture *sprite, Animacion animacion) :
        renderer(renderer),
        sprite(sprite),
        haciaAdelante(true),
        animacion(std::move(animacion)){}

void GraficoDePersonaje::actualizar(Mapeable &mapeable) {
    auto &personaje = dynamic_cast<Personaje &>(mapeable);

    Configuracion *config = Locator::configuracion();
    Posicion &posicion = personaje.posicion();
    SDL_Rect dimensiones = animacion.actualizarYDevolverPosicion();

    const int screenX = posicion.getX()
                        + posicion.getY() * cos(config->inclinacionDeEscenario)
                        - dimensiones.w / 2 * config->escalaDeGraficos;

    const int screenY = config->alturaDePantalla
                        + posicion.getZ()
                        - posicion.getY() * cos(M_PI / 2 - config->inclinacionDeEscenario)
                        - dimensiones.h * config->escalaDeGraficos;

    SDL_Rect posicionJugador = {screenX,
                                screenY,
                                int(dimensiones.w * config->escalaDeGraficos),
                                int(dimensiones.h * config->escalaDeGraficos)};

    if(personaje.velocidad().x != 0){
       haciaAdelante = personaje.velocidad().x > 0;
    }

    //Se renderiza en la ventana la imagen, la posicion del sprite, y la posicion del jugador
    if(haciaAdelante){
        SDL_RenderCopy(renderer, sprite, &dimensiones, &posicionJugador);
    } else {
        SDL_RenderCopyEx(renderer, sprite, &dimensiones, &posicionJugador, 180, nullptr, SDL_FLIP_VERTICAL);
    }
}
