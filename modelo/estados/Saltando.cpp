//
// Created by franco on 8/9/19.
//

#include "Saltando.h"
#include "DePie.h"

EstadoDePersonaje* Saltando::manejarEntrada(Personaje& personaje, const Uint8* entrada){

    Velocidad &velocidad = personaje.velocidad();
    if ( subiendo_ ) {
        if (alturaMaxima_ > 0) {
            velocidad.z -= 7;
            alturaMaxima_--;
        } else {
            subiendo_ = false;
            alturaMaxima_ = LIMITE;
        }
    } else if ( ! subiendo_ && alturaMaxima_ > 0){
        velocidad.z += 7;
        alturaMaxima_--;
    }else{
        return new DePie();
    }
    return nullptr;

}

void Saltando::actualizar(Personaje &personaje) {
    //EstadoDePersonaje::actualizar(personaje);
}
