//
// Created by felipe on 14/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEOBJETODESTRUIBLE_H
#define FINAL_FIGHT_GRAFICODEOBJETODESTRUIBLE_H


#include <SDL_system.h>
#include <vector>
#include "Grafico.h"
#include "Animacion.h"

using namespace std;

class GraficoDeObjetoDestruible : public Grafico {


private:
    SDL_Renderer* renderer;
    SDL_Texture *texture;
    int posicionX;
    int posicionY;

public:
    GraficoDeObjetoDestruible(SDL_Renderer* renderer, SDL_Texture * texture, int posicionX, int posicionY);
    ~GraficoDeObjetoDestruible() override = default;

    void actualizar(Mapeable &mapeable) override;
};


#endif //FINAL_FIGHT_GRAFICODEOBJETODESTRUIBLE_H
