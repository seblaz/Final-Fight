//
// Created by sebas on 1/11/19.
//

#include "PantallaAutenticador.h"

#include <utility>
#include "../ManagerPantallas.h"

PantallaAutenticador::PantallaAutenticador(IdPantalla id) :
        Pantalla(std::move(id)) {}

void PantallaAutenticador::actualizar(SDL_Event *e) {
    if (e->type == SDL_TEXTINPUT) {
        autenticador.ingresar(e->text.text);
    } else if (e->type == SDL_KEYDOWN) {
        if (e->key.keysym.sym == SDLK_BACKSPACE) {
            autenticador.borrar();
        } else if (e->key.keysym.sym == SDLK_TAB) {
            autenticador.cambiarCampo();
        } else if (e->key.keysym.scancode == SDL_SCANCODE_RETURN) {
            switch (autenticador.confirmar()) {
                case USUARIO_YA_CONECTADO:
                    manager->cambiarA("usuario ya conectado");
                    break;
                case PARTIDA_LLENA:
                    manager->cambiarA("partida llena");
                    break;
                case CONECTADO:
                    manager->cambiarA("juego");
                    break;
                case CONTRASENIA_INCORRECTA:
                    framesFaltantes = framesTotales;
            }
        }
    }
    framesFaltantes --;
    vista.actualizar(autenticador.getUsuario(), autenticador.getPassword(), framesFaltantes > 0);
}

