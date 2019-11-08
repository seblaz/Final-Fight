//
// Created by sebas on 7/11/19.
//

#ifndef FINAL_FIGHT_VISTAPUNTUACION_H
#define FINAL_FIGHT_VISTAPUNTUACION_H


#include <SDL_render.h>
#include "Vista.h"
#include "../modelos/PuntuacionJugadores.h"

class VistaPuntuacion : public Vista {

private:
    PuntuacionJugadores *puntuaciones;

public:
    explicit VistaPuntuacion(PuntuacionJugadores *puntuaciones);
    void graficar(SDL_Renderer *renderer) override;

};


#endif //FINAL_FIGHT_VISTAPUNTUACION_H
