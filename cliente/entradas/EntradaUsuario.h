//
// Created by sebas on 9/10/19.
//

#ifndef FINAL_FIGHT_ENTRADAUSUARIO_H
#define FINAL_FIGHT_ENTRADAUSUARIO_H


#include <mutex>
#include <SDL_events.h>
#include "../../modelo/serializables/Accion.h"
#include "../../utils/Socket.h"
#include "../../modelo/serializables/Personaje.h"
#include "../../servicios/Configuracion.h"

/**
 * Lectura de input de usuario.
 */
class EntradaUsuario {

public:
    virtual Accion *getAccion(SDL_Event *e) = 0;

};

#endif //FINAL_FIGHT_ENTRADAUSUARIO_H
