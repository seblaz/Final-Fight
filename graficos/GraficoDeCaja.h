//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODECAJA_H
#define FINAL_FIGHT_GRAFICODECAJA_H


#include "Grafico.h"

class GraficoDeCaja : public Grafico{
private:
    SDL_Renderer* renderer;
    SDL_Texture *texture = nullptr;

public:
    explicit GraficoDeCaja(SDL_Renderer* renderer) : renderer(renderer) {};
    ~GraficoDeCaja() override;

    void actualizar(Mapeable &mapeable) override;
};


#endif //FINAL_FIGHT_GRAFICODECAJA_H
