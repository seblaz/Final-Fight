//
// Created by felipe on 14/9/19.
//



#include "../modelo/Mapa.h"
#include "FisicaDeObjetoInteractuable.h"
#include "../modelo/mapeables/Objeto.h"

void FisicaDeObjetoInteractuable::actualizar(Mapa &mapa, Mapeable &mapeable) {
    auto &objeto = dynamic_cast<Objeto &>(mapeable);
    // TODO: Fisica del objeto... Debemos dividirlo en 2. En objetos agarrables o destruibles
}
