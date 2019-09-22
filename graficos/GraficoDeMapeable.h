//
// Created by felipe on 14/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEMAPEABLE_H
#define FINAL_FIGHT_GRAFICODEMAPEABLE_H


#include <SDL_system.h>
#include <vector>
#include "Grafico.h"
#include "Animacion.h"
#include "../fisica/FisicaDeMapeable.h"
#include "../fisica/FisicaDeEscenario.h"

using namespace std;

class GraficoDeMapeable : public Grafico {


private:
    FisicaDeMapeable *fisica;
    SDL_Texture *sprite;
    Animacion *animacion;
    FisicaDeEscenario &fisicaDeEscenario;

public:
    GraficoDeMapeable(FisicaDeMapeable *fisica, FisicaDeEscenario &fisicaDeEscenario,
                      SDL_Texture *sprite, Animacion *animacion);
    void actualizar(SDL_Renderer *renderer) override;
    int profundidad() override;
};


#endif //FINAL_FIGHT_GRAFICODEMAPEABLE_H
