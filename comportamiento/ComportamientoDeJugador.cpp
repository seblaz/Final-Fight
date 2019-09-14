//
// Created by sebas on 2/9/19.
//

#include <SDL_system.h>
#include "iostream"
#include "../servicios/Locator.h"
#include "../modelo/estados/Agachar.h"
#include "../modelo/estados/Saltar.h"
#include "../modelo/estados/MoverDerecha.h"
#include "../modelo/estados/MoverIzquierda.h"
#include "../modelo/estados/MoverArriba.h"
#include "../modelo/estados/MoverAbajo.h"
#include "../modelo/estados/Parado.h"

#include "ComportamientoDeJugador.h"

using namespace std;

#define RAPIDEZ 3

ComportamientoDeJugador::ComportamientoDeJugador() {
    estado_ = nullptr;
}

ComportamientoDeJugador::~ComportamientoDeJugador() {
    delete estado_;
}

void ComportamientoDeJugador::actualizar(Mapeable &mapeable) {
    Personaje& personaje = (Personaje&)(mapeable);
    const Uint8 *currentKeyStates = SDL_GetKeyboardState(nullptr);
    Velocidad &velocidad = personaje.velocidad();

    // TODO: implementar el patron Command para eliminar los ifs.
    velocidad.x = 0;
    velocidad.y = 0;
    velocidad.z = 0;

    float velocidadRelativa = Locator::configuracion()->velocidadDeJuego;

    EstadoDePersonaje * movimiento;

    if (currentKeyStates[SDL_SCANCODE_RIGHT]){
        movimiento = (MoverDerecha*) new MoverDerecha();
        velocidad.x = RAPIDEZ*velocidadRelativa;
    }
    if (currentKeyStates[SDL_SCANCODE_LEFT]){
        movimiento = (MoverIzquierda*) new MoverIzquierda();
        velocidad.x = -RAPIDEZ*velocidadRelativa;
    }
    if (currentKeyStates[SDL_SCANCODE_UP]){
        movimiento = (MoverArriba*) new MoverArriba();
        velocidad.y = RAPIDEZ*velocidadRelativa;
    }
    if (currentKeyStates[SDL_SCANCODE_DOWN]){
        movimiento = (MoverAbajo*) new MoverAbajo();
        velocidad.y = -RAPIDEZ*velocidadRelativa;
    }

    if(currentKeyStates[SDL_SCANCODE_D]) {
        movimiento = (Saltar*) new Saltar();
    }

    if(currentKeyStates[SDL_SCANCODE_S]) {
        movimiento = (Agachar*) new Agachar();
    }

    else{
        movimiento = (Parado*) new Parado();
    }

    movimiento->manejarEntrada(personaje);

    //EstadoDePersonaje* estado = estado_-> manejarEntrada(personaje, currentKeyStates);

    if (!movimiento){
        delete estado_;
        this -> estado_ = movimiento;
    }
}