//
// Created by sebas on 10/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODEESCENARIO_H
#define FINAL_FIGHT_GRAFICODEESCENARIO_H


#include <SDL_system.h>
#include <string>
#include "../modelo/mapeables/Mapeable.h"

using namespace std;

class GraficoDeEscenario : public Grafico {

private:
    SDL_Renderer *renderer;
    SDL_Texture *texture;
    int posicionY;

public:
    explicit GraficoDeEscenario(SDL_Renderer* renderer, SDL_Texture *texturaSprite, int posicionY);
    ~GraficoDeEscenario() = default;

    void actualizar() override;

};


#endif //FINAL_FIGHT_GRAFICODEESCENARIO_H
