//
// Created by sebas on 18/9/19.
//

#ifndef FINAL_FIGHT_NIVEL1_H
#define FINAL_FIGHT_NIVEL1_H


#include "../modelo/Mapa.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../graficos/sprite/Sprite.h"
#include "../graficos/GraficoDeEscenario.h"

class Nivel1 {

public:
    Nivel1();
    Mapeable* generarEscenario(SDL_Renderer *renderer, FisicaDePersonaje *fisicaDeJugador);

};


#endif //FINAL_FIGHT_NIVEL1_H
