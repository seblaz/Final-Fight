//
// Created by sebas on 13/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEPERSONAJE_H
#define FINAL_FIGHT_GRAFICODEPERSONAJE_H


#include <SDL_system.h>
#include <vector>
#include "Grafico.h"
#include "Animacion.h"
#include "../fisica/FisicaDePersonaje.h"
#include "GraficoDeMapeable.h"

using namespace std;

class GraficoDePersonaje : public Grafico {

private:
    SDL_Texture *sprite;
    Animacion *animacion;
    FisicaDePersonaje *fisica;
    FisicaDeEscenario &fisicaDeEscenario;
    bool haciaAdelante;
    Comportamiento *comportamiento;

public:
    GraficoDePersonaje(FisicaDePersonaje *fisica, FisicaDeEscenario &fisicaDeEscenario,
                       SDL_Texture *sprite, Animacion *animacion, Comportamiento *comportamiento);

    void actualizar(SDL_Renderer *renderer) override;
    void cambiarAnimacion(Animacion* nuevaAnimacion);
    int profundidad() override;
};


#endif //FINAL_FIGHT_GRAFICODEPERSONAJE_H
