//
// Created by sebas on 10/9/19.
//

#ifndef FINAL_FIGHT_ESCENARIO_H
#define FINAL_FIGHT_ESCENARIO_H


#include "Mapeable.h"
#include "../Mapa.h"
#include "../../comportamiento/Comportamiento.h"

class Escenario : public Mapeable {

public:
    Escenario(int x, int y, int z, Mapa *mapa, Fisica *fisica, Grafico *grafico);
    ~Escenario() = default;

    void actualizar(SDL_Renderer *renderer) override;
};


#endif //FINAL_FIGHT_ESCENARIO_H
