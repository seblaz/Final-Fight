//
// Created by sebas on 6/11/19.
//

#include "EntradaAutenticador.h"

EntradaAutenticador::EntradaAutenticador(Autenticador *autenticador) :
        autenticador(autenticador) {}

Accion *EntradaAutenticador::getAccion(SDL_Event *e) {
    if (e->type == SDL_TEXTINPUT) {
        autenticador->ingresar(e->text.text);
    } else if (e->type == SDL_KEYDOWN) {
        if (e->key.keysym.sym == SDLK_BACKSPACE) {
            autenticador->borrar();
        } else if (e->key.keysym.sym == SDLK_TAB) {
            autenticador->cambiarCampo();
        } else if (e->key.keysym.scancode == SDL_SCANCODE_RETURN) {
            return new AccionEnviarUsuario(new Usuario(autenticador->getUsuario(), autenticador->getPassword()));
        }
    }
    return new Accion(NULA);
}