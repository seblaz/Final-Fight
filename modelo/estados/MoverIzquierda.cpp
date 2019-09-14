//
// Created by franco on 13/9/19.
//

#include "MoverIzquierda.h"

void MoverIzquierda::manejarEntrada(Personaje &personaje){

    //Actualizar posicion de jugador

    //Llamar a graficar.derecha()

    //Refrescar
}

MoverIzquierda::MoverIzquierda() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se instancio un objeto de clase moverIzquierda");
}

MoverIzquierda::~MoverIzquierda() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se elimino un objeto de clase moverIzquierda");
}