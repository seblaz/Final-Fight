//
// Created by sebas on 2/9/19.
//

#include <SDL_system.h>
#include "ComportamientoDeJugador.h"
#include "../modelo/estados/Parado.h"
#include "../modelo/estados/Saltando.h"
#include "iostream"
#include "../servicios/Locator.h"

using namespace std;

#define RAPIDEZ 4

ComportamientoDeJugador::ComportamientoDeJugador(FisicaDePersonaje *fisica) :
        fisica(fisica),
        estado_(new Parado()){
        animacionActual = estado_ ->devolverAnimacion();
}

ComportamientoDeJugador::~ComportamientoDeJugador() {
    delete estado_;
    delete animacionActual;
}

void ComportamientoDeJugador::actualizar() {
    const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);

    // TODO: implementar el patron Command para eliminar los ifs.
    float velocidad_x = 0;
    float velocidad_y = 0;

    float velocidadRelativa = Locator::configuracion()->velocidadDeJuego;

    if (currentKeyStates[SDL_SCANCODE_RIGHT]) {
        velocidad_x = RAPIDEZ * velocidadRelativa;
    }
    if (currentKeyStates[SDL_SCANCODE_LEFT]) {
        velocidad_x = -RAPIDEZ * velocidadRelativa;
    }
    if (currentKeyStates[SDL_SCANCODE_UP]) {
        velocidad_y = RAPIDEZ * velocidadRelativa;
    }
    if (currentKeyStates[SDL_SCANCODE_DOWN]) {
        velocidad_y = -RAPIDEZ * velocidadRelativa;
    }
    fisica->cambiarVelocidadX(velocidad_x);
    fisica->cambiarVelocidadY(velocidad_y);

    EstadoDePersonaje *estado = estado_->manejarEntrada(fisica, currentKeyStates);

    if (nullptr != estado) {
        delete estado_;
        this->estado_ = estado;
        animacionActual = estado_ -> devolverAnimacion();
    }
}

Animacion* ComportamientoDeJugador::devolverAnimacion(){
    return animacionActual;
}