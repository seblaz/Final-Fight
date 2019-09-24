//
// Created by felipe on 22/9/19.
//

#include "Patrullar.h"
#include "../../servicios/Locator.h"
#include "../../graficos/FabricaDeAnimacionesDePoison.h"
#include "../../modelo/Velocidad.h"

Patrullar::Patrullar() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Patrullar");
}

Patrullar::~Patrullar() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se elimino un objeto de clase Patrullar");
}

#define RAPIDEZ 4

void Patrullar::actualizar(Entidad *entidad) {


    float velocidadRelativa = Locator::configuracion()->getFloatValue("/velocidad/juego");
    auto* velocidad = entidad->getEstado<Velocidad>("velocidad");

    velocidad->x = 0;
    velocidad->y = 0;

    //ALGORITMO PATRULLA LOL!
    if (movimientoAnterior == 0) {
        if ((rand() % 100) > 50) {
            velocidad->x = RAPIDEZ * velocidadRelativa;
            movimientoAnterior = 1;
        } else {
            velocidad->x = -RAPIDEZ * velocidadRelativa;
            movimientoAnterior = -1;
        }
    }

    if (movimientoAnterior == -1 && contadorDePasos != 100) {
        velocidad->x = -RAPIDEZ * velocidadRelativa;
        contadorDePasos++;
    } else if (movimientoAnterior == 1 && contadorDePasos != 100) {
        velocidad->x = RAPIDEZ * velocidadRelativa;
        contadorDePasos++;
    } else {
        movimientoAnterior = -movimientoAnterior;
        contadorDePasos = 0;
    }

}

void Patrullar::enter(Entidad *entidad) {
    auto* animacion = FabricaDeAnimacionesDePoison::caminando();
    entidad->agregarEstado("animacion", animacion);
}