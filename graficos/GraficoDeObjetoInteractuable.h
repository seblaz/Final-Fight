//
// Created by felipe on 14/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEOBJETOINTERACTUABLE_H
#define FINAL_FIGHT_GRAFICODEOBJETOINTERACTUABLE_H


#include <SDL_system.h>
#include <vector>
#include "Grafico.h"
#include "Animacion.h"

using namespace std;

class GraficoDeObjetoInteractuable : public Grafico {


private:
    SDL_Renderer* renderer;
    SDL_Texture *texture;
    int posicionX;
    int posicionY;

public:
    GraficoDeObjetoInteractuable(SDL_Renderer* renderer, SDL_Texture * texture, int posicionX, int posicionY);
    ~GraficoDeObjetoInteractuable() override = default;

    void actualizar(Mapeable &mapeable) override;
};


#endif //FINAL_FIGHT_GRAFICODEOBJETOINTERACTUABLE_H
