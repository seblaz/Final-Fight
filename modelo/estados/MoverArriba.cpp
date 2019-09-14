//
// Created by franco on 13/9/19.
//

#include "MoverArriba.h"

void MoverArriba::manejarEntrada(Personaje &personaje){

    //Actualizar posicion de jugador

    //Llamar a graficar.arriba()

    //Refrescar
}

MoverArriba::MoverArriba() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se instancio un objeto de clase moverArriba");
}

MoverArriba::~MoverArriba() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se elimino un objeto de clase moverArriba");
}

