//
// Created by sebas on 8/11/19.
//

#include "EntradaNula.h"

Accion *EntradaNula::getAccion(SDL_Event *e) {
    return new Accion(NULA);
}
