//
// Created by felipe on 14/9/19.
//



#include "FisicaDeMapeable.h"

FisicaDeMapeable::FisicaDeMapeable(int x, int y, int z) :
    posicion_(x, y, z) {}

Posicion FisicaDeMapeable::posicion() {
    return posicion_;
}
