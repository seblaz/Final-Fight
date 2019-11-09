//
// Created by sebas on 7/11/19.
//

#ifndef FINAL_FIGHT_ENTRADAPUNTUACION_H
#define FINAL_FIGHT_ENTRADAPUNTUACION_H


#include "EntradaUsuario.h"

class EntradaPuntuacion : public EntradaUsuario {

public:
    Accion *getAccion(SDL_Event *e) override;

};


#endif //FINAL_FIGHT_ENTRADAPUNTUACION_H
