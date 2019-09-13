//
// Created by sebas on 13/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEPERSONAJE_H
#define FINAL_FIGHT_GRAFICODEPERSONAJE_H


#include <SDL_system.h>
#include <vector>
#include "Grafico.h"
#include "Animacion.h"

using namespace std;

class GraficoDePersonaje : public Grafico {

private:
    SDL_Renderer* renderer;
    SDL_Texture * sprite;
    bool haciaAdelante;
    Animacion animacion;

public:
    GraficoDePersonaje(SDL_Renderer* renderer, SDL_Texture * sprite, Animacion animacion);

    void actualizar(Mapeable &mapeable) override;
};


#endif //FINAL_FIGHT_GRAFICODEPERSONAJE_H
