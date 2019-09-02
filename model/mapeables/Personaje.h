//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_PERSONAJE_H
#define FINAL_FIGHT_PERSONAJE_H


#include <string>
#include "Mapeable.h"

using namespace std;

class Personaje : Mapeable {

private:
    std::string nombre;

public:
    Personaje(int x, int y, int z, Graphics *graphics, string nombre);

};


#endif //FINAL_FIGHT_PERSONAJE_H
