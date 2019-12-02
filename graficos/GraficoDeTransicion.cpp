//
// Created by sebas on 23/9/19.
//

#include <SDL_system.h>
#include "GraficoDeTransicion.h"
#include "../servicios/Locator.h"
#include "../modelo/serializables/Posicion.h"
#include "../modelo/serializables/Opacidad.h"

GraficoDeTransicion::GraficoDeTransicion(Entidad *entidad) : Comportamiento(entidad) {}

void GraficoDeTransicion::actualizar() {
    SDL_Renderer *renderer = Locator::renderer();
    Configuracion *config = Locator::configuracion();
    SDL_Rect rect = {0, 0, config->getIntValue("/resolucion/ancho"), config->getIntValue("/resolucion/alto")};
    auto* opacidad = entidad->getEstado<Opacidad>("opacidad");
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, opacidad->getOpacidad()); // 0 u 255
    SDL_RenderFillRect(renderer, &rect);
}
