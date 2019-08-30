//
// Created by sebas on 30/8/19.
//

#include "Direccion.h"
#include<cmath>

Direccion::Direccion(float x, float y, float z){
    float modulo = pow(pow(x, 2.0f) + pow(y, 2.0f) + pow(z, 2.0f), 0.5f);
    this->x = x / modulo;
    this->y = y / modulo;
    this->z = z / modulo;
}