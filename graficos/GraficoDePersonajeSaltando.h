//
// Created by sebas on 12/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEPERSONAJESALTANDO_H
#define FINAL_FIGHT_GRAFICODEPERSONAJESALTANDO_H


#include <SDL_system.h>
#include "Grafico.h"

class GraficoDePersonajeSaltando : public Grafico {

private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int spriteActual;
    const int cantidadDeSprites;
    const SDL_Rect coordenadasSprites[4];
    int framesFaltantes;

public:
    explicit GraficoDePersonajeSaltando(SDL_Renderer*renderer, SDL_Texture *texturaSprite);

    ~GraficoDePersonajeSaltando() override = default;

    void actualizar(Mapeable &mapeable) override;

};


#endif //FINAL_FIGHT_GRAFICODEPERSONAJESALTANDO_H
