//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_MAPEABLE_H
#define FINAL_FIGHT_MAPEABLE_H


#include "Posicion.h"
#include "../graphics/Graphics.h"

using namespace std;

class Mapeable {

private:
    Posicion posicion;
    Graphics graphics;

public:
    Mapeable(int x, int y, int z, Graphics &graphics);
    void actualizar(SDL_Surface* surface);
};


#endif //FINAL_FIGHT_MAPEABLE_H
