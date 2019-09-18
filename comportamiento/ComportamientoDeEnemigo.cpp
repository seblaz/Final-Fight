//
// Created by sebas on 2/9/19.
//

#include <SDL_system.h>
#include "ComportamientoDeEnemigo.h"
#include "../modelo/estados/Caminando.h"
#include "iostream"

using namespace std;

#define RAPIDEZ 3

ComportamientoDeEnemigo::ComportamientoDeEnemigo(FisicaDePersonaje *fisica) :
        fisica(fisica),
        estado_(new Caminando()),
        animacionActual(FabricaDeAnimacionesDePoison::caminando()){
}

ComportamientoDeEnemigo::~ComportamientoDeEnemigo() {
    delete estado_;
    delete animacionActual;
}

void ComportamientoDeEnemigo::actualizar() {

    // TODO: implementar el patron Command para eliminar los ifs.
    float velocidad_x = 0;
    float velocidad_y = 0;

    float velocidadRelativa = Locator::configuracion()->getFloatValue("/velocidadDeJuego");

    //ALGORITMO PATRULLA LOL!
    if (movimientoAnterior == 0) {
        if ((rand() % 100) > 50) {
            velocidad_x = RAPIDEZ * velocidadRelativa;
            movimientoAnterior = 1;
        } else {
            velocidad_x = -RAPIDEZ * velocidadRelativa;
            movimientoAnterior = -1;
        }
    }

    if (movimientoAnterior == -1 && contadorDePasos != 100) {
        velocidad_x = -RAPIDEZ * velocidadRelativa;
        contadorDePasos++;
    } else if (movimientoAnterior == 1 && contadorDePasos != 100) {
        velocidad_x = RAPIDEZ * velocidadRelativa;
        contadorDePasos++;
    } else {
        movimientoAnterior = -movimientoAnterior;
        contadorDePasos = 0;
    }

    fisica->cambiarVelocidadX(velocidad_x);
    fisica->cambiarVelocidadY(velocidad_y);


}

Animacion *ComportamientoDeEnemigo::devolverAnimacion() {
    return animacionActual;
}
