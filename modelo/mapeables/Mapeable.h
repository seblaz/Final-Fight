//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPEABLE_H
#define FINAL_FIGHT_MAPEABLE_H


#include "../Posicion.h"
#include "../../graficos/Grafico.h"

using namespace std;

class Fisica;
class Mapa;

class Mapeable {

private:
    Posicion _posicion;
    Grafico *grafico;
    Fisica *physics;

protected:
    Mapa *mapa;

public:
    Mapeable(int x, int y, int z, Mapa *mapa, Fisica *fisica, Grafico *grafico);
    virtual void actualizar(SDL_Renderer *renderer);
    Posicion &posicion();
};

#include "../../fisica/Fisica.h"
#include "../Mapa.h"

#endif //FINAL_FIGHT_MAPEABLE_H
