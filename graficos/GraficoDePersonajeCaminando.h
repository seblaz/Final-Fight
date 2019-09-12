//
// Created by sebas on 12/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEPERSONAJECAMINANDO_H
#define FINAL_FIGHT_GRAFICODEPERSONAJECAMINANDO_H


#include <SDL_system.h>
#include "Grafico.h"

class GraficoDePersonajeCaminando : public Grafico{

private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int spriteActual;
    const int cantidadDeSprites;
    const SDL_Rect coordenadasSprites[6];

public:
    explicit GraficoDePersonajeCaminando(SDL_Renderer* renderer, SDL_Texture * texturaSprite);
    ~GraficoDePersonajeCaminando() override = default;

    void actualizar(Mapeable &mapeable) override;

};


#endif //FINAL_FIGHT_GRAFICODEPERSONAJECAMINANDO_H
