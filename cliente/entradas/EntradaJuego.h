//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_ENTRADAJUEGO_H
#define FINAL_FIGHT_ENTRADAJUEGO_H


#include "EntradaUsuario.h"

class EntradaJuego : public EntradaUsuario {

public:
    Accion *getAccion(SDL_Event *e) override;

};


#endif //FINAL_FIGHT_ENTRADAJUEGO_H
