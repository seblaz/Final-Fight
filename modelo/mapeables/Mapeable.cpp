//
// Created by sebas on 30/8/19.
//

#include "Mapeable.h"
#include "../../comportamiento/Comportamiento.h"

Mapeable::Mapeable(Fisica *fisica, Grafico *grafico, Comportamiento *comportamiento) :
        grafico_(grafico),
        fisica_(fisica),
        comportamiento_(comportamiento) {}