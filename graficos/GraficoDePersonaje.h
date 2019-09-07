//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEPERSONAJE_H
#define FINAL_FIGHT_GRAFICODEPERSONAJE_H


#include "Grafico.h"

class GraficosDePersonaje : public Grafico {

private:
    SDL_Texture *texture = nullptr;

public:
    void actualizar(SDL_Renderer *renderer, Mapeable &mapeable) override;
    ~GraficosDePersonaje() override = default;;
};


#endif //FINAL_FIGHT_GRAFICODEPERSONAJE_H
