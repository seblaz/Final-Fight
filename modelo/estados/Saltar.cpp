//
// Created by franco on 8/9/19.
//

#include "Saltar.h"

void Saltar::manejarEntrada(Personaje& personaje){

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
    }/*else{
        return new Parado();
    }*/

    //Llamar a graficador.personaje.saltar(personaje);

    //Refrescar
}

Saltar::Saltar() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se instancio un objeto de clase Saltar");
}

Saltar::~Saltar() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se elimino un objeto de clase Saltar");
}