//
// Created by sebas on 30/10/19.
//

#ifndef FINAL_FIGHT_AUTENTICADOR_H
#define FINAL_FIGHT_AUTENTICADOR_H


#include <SDL_system.h>
#include "../usuario/Usuario.h"

class Autenticador {

private:
    void generarFormulario(SDL_Renderer *renderer);
    void generarFondo(SDL_Renderer *renderer);

public:
    Usuario *getUsuario(SDL_Event *pEvent);
};


#endif //FINAL_FIGHT_AUTENTICADOR_H
