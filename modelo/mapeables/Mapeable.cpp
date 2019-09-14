//
// Created by sebas on 30/8/19.
//

#include "Mapeable.h"
#include "../../comportamiento/Comportamiento.h"

Mapeable::Mapeable(Fisica *fisica, Grafico *grafico, Comportamiento *comportamiento) :
        grafico(grafico),
        fisica(fisica),
        comportamiento(comportamiento) {}

void Mapeable::actualizar() {
    comportamiento->actualizar();
    fisica->actualizar();
    grafico->actualizar();
}