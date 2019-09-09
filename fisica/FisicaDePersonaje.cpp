//
// Created by sebas on 2/9/19.
//

#include "FisicaDePersonaje.h"
#include "../modelo/mapeables/Personaje.h"

void FisicaDePersonaje::actualizar(Mapa &mapa, Mapeable &mapeable) {
    auto &personaje = dynamic_cast<Personaje &>(mapeable);
    Posicion &posicion = personaje.posicion();
    Velocidad &velocidad = personaje.velocidad();
    posicion.mover(velocidad);
}
