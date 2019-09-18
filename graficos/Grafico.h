//
// Created by sebas on 1/9/19.
//

#ifndef FINAL_FIGHT_GRAFICO_H
#define FINAL_FIGHT_GRAFICO_H


#include <SDL_system.h>
#include "../modelo/Posicion.h"
#include "../servicios/Configuracion.h"
#include "../servicios/Locator.h"

class Grafico {

public:
    virtual void actualizar(SDL_Renderer *renderer) = 0;
    virtual int profundidad() = 0;
};

SDL_Rect calcularPosicionEnPantalla(Posicion posicionEnMapa, SDL_Rect posicionEnSprite, float esacalaDeAnimacion);


#endif //FINAL_FIGHT_GRAFICO_H
