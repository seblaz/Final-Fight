//
// Created by sebas on 21/9/19.
//

#include "Entidad.h"

IdEntidad Entidad::ultimoId = 0;

Entidad::Entidad() {
    idEntidad = ultimoId++;
}

IdEntidad Entidad::getId() {
    return idEntidad;
}
