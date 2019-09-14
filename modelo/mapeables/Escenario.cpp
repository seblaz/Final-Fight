//
// Created by sebas on 10/9/19.
//

#include "Escenario.h"

Escenario::Escenario(int x, int y, int z, Mapa *mapa, Fisica *fisica, Grafico *grafico) :
        Mapeable(fisica, grafico, nullptr) {}

void Escenario::actualizar() {
    Mapeable::actualizar();
}
