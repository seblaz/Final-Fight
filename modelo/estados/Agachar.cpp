//
// Created by franco on 8/9/19.
//

#include "Agachar.h"

void Agachar::manejarEntrada(Personaje &personaje) {
    Velocidad &velocidad = personaje.velocidad();
    velocidad.x = 0;
    velocidad.y = 0;
    velocidad.z = 0;

    //Llamar a graficador.personaje.abajo(personaje);

    //Refrescar
}

Agachar::Agachar() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se instancio un objeto de clase Agachar");
}

Agachar::~Agachar() {
    Logger logger(DEBUG);
    logger.log(DEBUG, "Se elimino un objeto de clase Agachar");
}

