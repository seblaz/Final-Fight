//
// Created by sebas on 6/11/19.
//

#include "EntradaJuego.h"

Accion *EntradaJuego::getAccion(SDL_Event *e) {
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);

    ACCION accion;
    if (entrada[SDL_SCANCODE_A]) {
        accion = GOLPEAR;
    } else if (entrada[SDL_SCANCODE_S]) {
        accion = SALTAR;
    } else if (entrada[SDL_SCANCODE_D]) {
        accion = AGACHAR;
    } else if (entrada[SDL_SCANCODE_LEFT] && entrada[SDL_SCANCODE_UP]) {
        accion = CAM_IZQUIERDA_ARRIBA;
    } else if (entrada[SDL_SCANCODE_LEFT] && entrada[SDL_SCANCODE_DOWN]) {
        accion = CAM_IZQUIERDA_ABAJO;
    } else if (entrada[SDL_SCANCODE_RIGHT] && entrada[SDL_SCANCODE_UP]) {
        accion = CAM_DERECHA_ARRIBA;
    } else if (entrada[SDL_SCANCODE_RIGHT] && entrada[SDL_SCANCODE_DOWN]) {
        accion = CAM_DERECHA_ABAJO;
    } else if (entrada[SDL_SCANCODE_LEFT]) {
        accion = CAM_IZQUIERDA;
    } else if (entrada[SDL_SCANCODE_RIGHT]) {
        accion = CAM_DERECHA;
    } else if (entrada[SDL_SCANCODE_UP]) {
        accion = CAM_ARRIBA;
    } else if (entrada[SDL_SCANCODE_DOWN]) {
        accion = CAM_ABAJO;
    } else if (e && e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_t) {
        accion = MODOTEST;
    } else {
        accion = REPOSAR;
    }
    return new Accion(accion);
}
