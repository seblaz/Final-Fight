//
// Created by sebas on 1/11/19.
//

#ifndef FINAL_FIGHT_PANTALLA_H
#define FINAL_FIGHT_PANTALLA_H


#include <SDL_events.h>
#include <string>
#include <SDL_render.h>
#include "../interpretes/InterpreteCliente.h"
#include "../entradas/EntradaUsuario.h"
#include "../vistas/Vista.h"

using namespace std;

typedef string IdPantalla;

class ManagerPantallas;

class Pantalla {

private:
    IdPantalla id;

protected:
    ManagerPantallas *manager = nullptr;
    InterpreteCliente *interprete;
    EntradaUsuario *entradaUsuario;
    Vista *vista;

public:
    explicit Pantalla(IdPantalla id, InterpreteCliente *interprete, EntradaUsuario *entradaUsuario, Vista *vista);
    IdPantalla getId();
    void setManager(ManagerPantallas *manager);

    void interpretar(stringstream &s);
    void graficar(SDL_Renderer *renderer);
    Accion *getAccion(SDL_Event *e);

};


#endif //FINAL_FIGHT_PANTALLA_H
