//
// Created by sebas on 2/9/19.
//

#include <SDL_system.h>
#include "ComportamientoDeEnemigo.h"
#include "../modelo/estados/Caminando.h"
#include "../modelo/estados/Saltando.h"
#include "iostream"
#include "../servicios/Locator.h"

using namespace std;

#define RAPIDEZ 3

ComportamientoDeEnemigo::ComportamientoDeEnemigo() {
    estado_ = new Caminando();
    contadorDePasos = 0;
    movimientoAnterior = 0;
}

ComportamientoDeEnemigo::~ComportamientoDeEnemigo() {
    delete estado_;
}

void ComportamientoDeEnemigo::actualizar(Mapeable &mapeable) {

    Personaje &personaje = (Personaje &) (mapeable);

    Velocidad &velocidad = personaje.velocidad();

    // TODO: implementar el patron Command para eliminar los ifs.
    velocidad.x = 0;
    velocidad.y = 0;
    velocidad.z = 0;

    float velocidadRelativa = Locator::configuracion()->velocidadDeJuego;

    //ALGORITMO PATRULLA LOL!
    if (movimientoAnterior == 0) {
        if ((rand() % 100) > 50) {
            velocidad.x = RAPIDEZ * velocidadRelativa;
            movimientoAnterior = 1;
        } else {
            velocidad.x = -RAPIDEZ * velocidadRelativa;
            movimientoAnterior = -1;
        }
    }

    if (movimientoAnterior == -1 && contadorDePasos != 100) {
        velocidad.x = -RAPIDEZ * velocidadRelativa;
        contadorDePasos++;
    } else if (movimientoAnterior == 1 && contadorDePasos != 100) {
        velocidad.x = RAPIDEZ * velocidadRelativa;
        contadorDePasos++;
    } else {
        movimientoAnterior = -movimientoAnterior;
        contadorDePasos = 0;
    }
}
