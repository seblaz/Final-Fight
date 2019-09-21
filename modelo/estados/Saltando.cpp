//
// Created by franco on 8/9/19.
//

#include "Saltando.h"

EstadoDePersonaje* Saltando::manejarEntrada(FisicaDePersonaje *fisica, const Uint8* entrada){

    Velocidad velocidad = fisica->velocidad();
    if ( subiendo_ ) {
        if (alturaMaxima_ > 0) {
            fisica->cambiarVelocidadZ(-7);
            alturaMaxima_--;
        } else {
            subiendo_ = false;
            alturaMaxima_ = LIMITE;
        }
    } else if (alturaMaxima_ > 0){
        fisica->cambiarVelocidadZ( 7);
        alturaMaxima_--;
    }else{
        fisica->cambiarVelocidadZ( 0);
        return new Parado();
    }
    return nullptr;
}

Saltando::Saltando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Saltando");
}

Saltando::~Saltando() {
    Logger* logger = Locator::logger();
    logger->log(DEBUG, "Se elimino un objeto de clase Saltando");
}

Animacion * Saltando::devolverAnimacion() {
        return FabricaDeAnimacionesDeCody::saltando();
}
