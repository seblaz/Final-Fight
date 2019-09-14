//
// Created by felipe on 14/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEOBJETO_H
#define FINAL_FIGHT_GRAFICODEOBJETO_H


#include <SDL_system.h>
#include <vector>
#include "Grafico.h"
#include "Animacion.h"

using namespace std;

class GraficoDeObjeto : public Grafico {


private:
    SDL_Renderer* renderer;
    SDL_Texture *texture;

public:
    GraficoDeObjeto(SDL_Renderer* renderer, SDL_Texture * texture);
    ~GraficoDeObjeto() override = default;

    void actualizar(Mapeable &mapeable) override;
};


#endif //FINAL_FIGHT_GRAFICODEOBJETO_H
