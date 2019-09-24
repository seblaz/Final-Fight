//
// Created by sebas on 23/9/19.
//

#include <SDL_system.h>
#include "GraficoDeTransicion.h"
#include "../servicios/Locator.h"
#include "../modelo/Posicion.h"

GraficoDeTransicion::GraficoDeTransicion(int anchoDeEscenario) :
        anchoDeEscenario(anchoDeEscenario) {
    Configuracion* config = Locator::configuracion();
    framesPorTransicionInicial = config->getIntValue("/transicion/inicial/frames");
    framesFaltantesPorTranscionInicial = framesPorTransicionInicial;
    margenTransicionFinal = config->getIntValue("/transicion/final/margen");
}

void GraficoDeTransicion::actualizar(Entidad *entidad) {
    SDL_Renderer *renderer = Locator::renderer();
    Configuracion *config = Locator::configuracion();

    int posicionDeJugadorX = entidad->getEstado<Posicion>("posicion de jugador")->getX();

    SDL_Rect rect = {0, 0, config->getIntValue("/resolucion/ancho"), config->getIntValue("/resolucion/alto")};
    if ((anchoDeEscenario - posicionDeJugadorX) <= 0) {
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xff);
        SDL_RenderFillRect(renderer, &rect);
    } else if ((anchoDeEscenario - posicionDeJugadorX) > 0 && (anchoDeEscenario - posicionDeJugadorX) < margenTransicionFinal) {
        int opacidad = int((float)0xff * (1.0 - ((float)anchoDeEscenario - (float)posicionDeJugadorX) / (float)margenTransicionFinal));
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, opacidad);
        SDL_RenderFillRect(renderer, &rect);
    }

    if(framesFaltantesPorTranscionInicial > 0){
        int opacidad = int((float)0xff * ((float)framesFaltantesPorTranscionInicial / (float)framesPorTransicionInicial));
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, opacidad);
        SDL_RenderFillRect(renderer, &rect);
        framesFaltantesPorTranscionInicial--;
    }
}
