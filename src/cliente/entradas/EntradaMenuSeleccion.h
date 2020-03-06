//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_ENTRADAMENUSELECCION_H
#define FINAL_FIGHT_ENTRADAMENUSELECCION_H


#include "EntradaUsuario.h"
#include "../modelos/MenuSeleccion.h"

class EntradaMenuSeleccion:public EntradaUsuario
{

private:
  int framesPorAccion = 20;
  int framesInactivo = 20;
  MenuSeleccion *menu;

public:
    explicit EntradaMenuSeleccion (MenuSeleccion * menu);
  Accion *getAccion (SDL_Event * e) override;

};


#endif //FINAL_FIGHT_ENTRADAMENUSELECCION_H
