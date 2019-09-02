//
// Created by sebas on 30/8/19.
//

#include "Mapeable.h"
#include "../graphics/Graphics.h"

//class Graphics;

Mapeable::Mapeable(int x, int y, int z, Graphics &graphics) : posicion(x, y, z), graphics(graphics) {}

void Mapeable::actualizar(SDL_Surface* surface) {
    graphics.actualizar(surface, *this);
}
