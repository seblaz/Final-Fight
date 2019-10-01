//
// Created by sebas on 21/9/19.
//

#include "Entidad.h"
#include <algorithm>

IdEntidad Entidad::ultimoId = 0;

Entidad::Entidad() {
    idEntidad = ultimoId++;
}

IdEntidad Entidad::getId() {
    return idEntidad;
}

vector<Comportamiento *> Entidad::getComportamientos() {
    vector<Comportamiento *> values(comportamientos.size());
    auto value_selector = [](auto pair){return pair.second;};
    transform(comportamientos.begin(), comportamientos.end(), values.begin(), value_selector);
    return values;
}

vector<Estado *> Entidad::getEstados() {
    vector<Estado *> values(estados.size());
    auto value_selector = [](auto pair){return pair.second;};
    transform(estados.begin(), estados.end(), values.begin(), value_selector);
    return values;
}