//
// Created by franco on 8/9/19.
//

#include "Saltando.h"

EstadosDePersonaje* Saltando::manejarEntrada(Personaje& personaje, const Uint8* entrada){
    Velocidad &velocidad = personaje.velocidad();

    velocidad.z = 1;

}

void Saltando::actualizar(Personaje &personaje) {
    //EstadosDePersonaje::actualizar(personaje);
}
