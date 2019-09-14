//
// Created by felipe on 14/9/19.
//

#ifndef FINAL_FIGHT_OBJETO_H
#define FINAL_FIGHT_OBJETO_H


#include "Mapeable.h"
#include "../Mapa.h"

class Objeto : public Mapeable {

public:
    Objeto(int x, int y, int z, Mapa *mapa, Fisica *fisica, Grafico *grafico);
    ~Objeto() = default;

    void actualizar(SDL_Renderer *renderer) override;
};




#endif //FINAL_FIGHT_OBJETO_H

