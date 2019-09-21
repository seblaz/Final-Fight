//
// Created by franco on 13/9/19.
//

#include "Caminando.h"
#include "../servicios/Locator.h"
#include "Saltando.h"
#include "Agachado.h"
#include "../modelo/Velocidad.h"

Caminando::Caminando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Caminando");
}

Caminando::~Caminando() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Caminando");
}

#define RAPIDEZ 4

void Caminando::actualizar(Entidad *entidad) {
    float velocidadRelativa = Locator::configuracion()->getFloatValue("/velocidad/juego");
    auto* velocidad = entidad->getEstado<Velocidad>();
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);

    velocidad->x = 0;
    velocidad->y = 0;

    if (entrada[SDL_SCANCODE_RIGHT]) {
        velocidad->x = RAPIDEZ * velocidadRelativa;
    }
    if (entrada[SDL_SCANCODE_LEFT]) {
        velocidad->x = -RAPIDEZ * velocidadRelativa;
    }
    if (entrada[SDL_SCANCODE_UP]) {
        velocidad->y = RAPIDEZ * velocidadRelativa;
    }
    if (entrada[SDL_SCANCODE_DOWN]) {
        velocidad->y = -RAPIDEZ * velocidadRelativa;
    }

    if (entrada[SDL_SCANCODE_S]) { // Tecla S -> El personaje Salta
        EstadoDePersonaje* saltando = new Saltando();
        entidad->agregarComportamiento(saltando);
    }else if (entrada[SDL_SCANCODE_D]){
        EstadoDePersonaje* agachado = new Agachado();
        entidad->agregarComportamiento(agachado);
    }else if (entrada[SDL_SCANCODE_A]){
//        EstadoDePersonaje* golpeando = new Golpeando();
//        entidad->agregarComportamiento(golpeando);
    }else if (entrada[SDL_SCANCODE_RIGHT] || entrada[SDL_SCANCODE_LEFT] || entrada[SDL_SCANCODE_DOWN] || entrada[SDL_SCANCODE_UP]){

    }else {
        EstadoDePersonaje* parado = new Parado();
        entidad->agregarComportamiento(parado);
    }
}
