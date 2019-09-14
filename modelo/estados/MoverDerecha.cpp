//
// Created by franco on 13/9/19.
//

#include "MoverDerecha.h"

void MoverDerecha::manejarEntrada(Personaje &personaje){

    //Actualizar posicion de jugador

    //Llamar a graficar.derecha()

    //Refrescar

}

MoverDerecha::MoverDerecha() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se instancio un objeto de clase moverDerecha");
}

MoverDerecha::~MoverDerecha() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se elimino un objeto de clase moverDerecha");
}

