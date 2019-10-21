//
// Created by sebas on 3/10/19.
//

#ifndef FINAL_FIGHT_GRAFICOMENUSELECCION_H
#define FINAL_FIGHT_GRAFICOMENUSELECCION_H


#include <SDL_rect.h>
#include "../modelo/Entidad.h"
#include "../modelo/Posicion.h"

class GraficoMenuSeleccion : public Comportamiento {

public:
    void actualizar(Entidad*) override;
    SDL_Rect calcularPosicionEnPantalla(Posicion posicionEnMapa, SDL_Rect posicionEnSprite, float esacalaDeAnimacion);
};


#endif //FINAL_FIGHT_GRAFICOMENUSELECCION_H
