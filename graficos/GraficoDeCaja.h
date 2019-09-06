//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODECAJA_H
#define FINAL_FIGHT_GRAFICODECAJA_H


#include "Grafico.h"

class GraficoDeCaja : public Grafico{
private:
    SDL_Texture *texture = nullptr;

public:
    void actualizar(SDL_Renderer *renderer, Mapeable &mapeable) override;
    ~GraficoDeCaja() override;
};


#endif //FINAL_FIGHT_GRAFICODECAJA_H
