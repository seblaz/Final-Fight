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
}

ComportamientoDeEnemigo::~ComportamientoDeEnemigo() {
    delete estado_;
}

void ComportamientoDeEnemigo::actualizar(Mapeable &mapeable) {

    Personaje& personaje = (Personaje&)(mapeable);
    const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);

    Velocidad &velocidad = personaje.velocidad();

    // TODO: implementar el patron Command para eliminar los ifs.
    velocidad.x = 0;
    velocidad.y = 0;
    velocidad.z = 0;

    float velocidadRelativa = Locator::configuracion()->velocidadDeJuego;


    int v1 = rand() % 100;
    if (v1 > 50) {
        velocidad.x = -RAPIDEZ*velocidadRelativa;
    } else {
        velocidad.x = RAPIDEZ*velocidadRelativa;
    }

    EstadoDePersonaje* estado = estado_-> manejarEntrada(personaje, currentKeyStates);

    if (nullptr != estado){
        delete estado_;
        this -> estado_ = estado;
    }

}