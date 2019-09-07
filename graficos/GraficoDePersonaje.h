//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEPERSONAJE_H
#define FINAL_FIGHT_GRAFICODEPERSONAJE_H


#include "Grafico.h"

class GraficosDePersonaje : public Grafico {

private:
    SDL_Texture *texture = nullptr;
    SDL_Surface *sprite = nullptr;

public:
    void actualizar(SDL_Renderer *renderer, Mapeable &mapeable) override;
    ~GraficosDePersonaje() override = default;

    void setearSprite(SDL_Surface* spriteNuevo) { sprite = spriteNuevo; }
    SDL_Surface* obtenerSprite() const {return sprite;}
    void setearTextura(SDL_Texture* textureNueva) { texture = textureNueva; }
    SDL_Texture* obtenerTextura() const {return texture;}
};


#endif //FINAL_FIGHT_GRAFICODEPERSONAJE_H
