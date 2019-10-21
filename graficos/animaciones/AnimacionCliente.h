//
// Created by sebas on 13/9/19.
//

#ifndef FINAL_FIGHT_ANIMACIONCLIENTE_H
#define FINAL_FIGHT_ANIMACIONCLIENTE_H


#include <SDL_rect.h>
#include <vector>
#include "../../modelo/Entidad.h"

using namespace std;

class AnimacionCliente : public Estado {

private:
    vector<SDL_Rect> posiciones;
    float escala_;

public:
    AnimacionCliente(vector<SDL_Rect> posiciones, float escala = 1);
    SDL_Rect devolverPosicion(Entidad *entidad);
    float escala();

    void setPosicionesInicial( vector<SDL_Rect> posicionesInicial) { posiciones = posicionesInicial; }
    bool compareTo(AnimacionCliente *animacionAcomparar);
};


#endif //FINAL_FIGHT_ANIMACIONCLIENTE_H
