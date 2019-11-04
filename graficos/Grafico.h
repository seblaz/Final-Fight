//
// Created by sebas on 21/9/19.
//

#ifndef FINAL_FIGHT_GRAFICO_H
#define FINAL_FIGHT_GRAFICO_H


#include "../modelo/Entidad.h"
#include "../modelo/serializables/Posicion.h"
#include <SDL_rect.h>

class Grafico : public Comportamiento {

public:
    void actualizar(Entidad*) override;
};

SDL_Rect calcularPosicionEnPantalla(Posicion posicionEnMapa, SDL_Rect posicionEnSprite, float esacalaDeAnimacion);

#endif //FINAL_FIGHT_GRAFICO_H
