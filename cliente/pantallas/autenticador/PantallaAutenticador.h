//
// Created by sebas on 1/11/19.
//

#ifndef FINAL_FIGHT_PANTALLAAUTENTICADOR_H
#define FINAL_FIGHT_PANTALLAAUTENTICADOR_H


#include "Autenticador.h"
#include "VistaAutenticador.h"
#include "../Pantalla.h"

using namespace std;

class PantallaAutenticador : public Pantalla {

private:
    Autenticador autenticador;
    VistaAutenticador vista;
    int framesTotales = 60;
    int framesFaltantes = 0;

public:
    explicit PantallaAutenticador(IdPantalla id);
    void actualizar(SDL_Event *evento) override;

};


#endif //FINAL_FIGHT_PANTALLAAUTENTICADOR_H
