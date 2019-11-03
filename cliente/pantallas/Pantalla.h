//
// Created by sebas on 1/11/19.
//

#ifndef FINAL_FIGHT_PANTALLA_H
#define FINAL_FIGHT_PANTALLA_H


#include <SDL_events.h>
#include <string>

using namespace std;

typedef string IdPantalla;

class ManagerPantallas;

class Pantalla {

private:
    IdPantalla id;

protected:
    ManagerPantallas *manager = nullptr;

public:
    explicit Pantalla(IdPantalla id);
    IdPantalla getId();
    void setManager(ManagerPantallas *manager);

    virtual void actualizar(SDL_Event *e) = 0;
    virtual void iniciar() {};
    virtual void finalizar() {};

};


#endif //FINAL_FIGHT_PANTALLA_H
