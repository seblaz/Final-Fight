//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEPERSONAJEPARADO_H
#define FINAL_FIGHT_GRAFICODEPERSONAJEPARADO_H


#include "Grafico.h"
#include <string>

using namespace std;

class GraficosDePersonaje : public Grafico {

private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;

public:
    explicit GraficosDePersonaje(SDL_Renderer* renderer, SDL_Texture * texturaSprite);
    ~GraficosDePersonaje() override = default;

    void actualizar(Mapeable &mapeable) override;
};


#endif //FINAL_FIGHT_GRAFICODEPERSONAJEPARADO_H
