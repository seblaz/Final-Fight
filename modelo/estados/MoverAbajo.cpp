//
// Created by franco on 13/9/19.
//

#include "MoverAbajo.h"

void MoverAbajo::manejarEntrada(Personaje &personaje){

    //Actualizar posicion de jugador

    //Llamar a graficar.abajo()

    //Refrescar

}

MoverAbajo::MoverAbajo() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se instancio un objeto de clase moverAbajo");
}

MoverAbajo::~MoverAbajo() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se elimino un objeto de clase moverAbajo");
}

