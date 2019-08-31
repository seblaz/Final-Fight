//
// Created by sebas on 30/8/19.
//

#include "Personaje.h"

#include <utility>

Personaje::Personaje(int x, int y, int z, std::string nombre): Mapeable(x, y, z), nombre(std::move(nombre)) {}
