//
// Created by sebas on 23/9/19.
//

#include <SDL_system.h>
#include "GraficoDeTransicion.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"

GraficoDeTransicion::GraficoDeTransicion(int anchoDeEscenario) :
        anchoDeEscenario(anchoDeEscenario) {}

void GraficoDeTransicion::actualizar(Entidad *entidad) {
    SDL_Renderer *renderer = Locator::renderer();
    Configuracion *config = Locator::configuracion();

    int posicionDeJugadorX = entidad->getEstado<Posicion>("posicion de jugador")->getX();

    SDL_Rect rect = {0, 0, config->getIntValue("/resolucion/ancho", 0), config->getIntValue("/resolucion/alto", 0)};
    const int trans = 200;
    if ((anchoDeEscenario - posicionDeJugadorX) <= 0) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
        SDL_RenderFillRect(renderer, &rect);
    } else if ((anchoDeEscenario - posicionDeJugadorX) > 0 && (anchoDeEscenario - posicionDeJugadorX) < trans) {
        int opacidad = int((float)0xff * (1.0 - ((float)anchoDeEscenario - (float)posicionDeJugadorX) / (float)trans));
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, opacidad);
        SDL_RenderFillRect(renderer, &rect);
    }
}
