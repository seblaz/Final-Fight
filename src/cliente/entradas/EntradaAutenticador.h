//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_ENTRADAAUTENTICADOR_H
#define FINAL_FIGHT_ENTRADAAUTENTICADOR_H


#include "EntradaUsuario.h"
#include "../modelos/Autenticador.h"

class EntradaAutenticador:public EntradaUsuario
{

private:
  Autenticador * autenticador;

public:
  explicit EntradaAutenticador (Autenticador * autenticador);
  Accion *getAccion (SDL_Event * e) override;

};


#endif //FINAL_FIGHT_ENTRADAAUTENTICADOR_H
