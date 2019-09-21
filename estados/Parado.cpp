//
// Created by franco on 6/9/19.
//

#include "Parado.h"
#include "../servicios/Locator.h"
#include "Saltando.h"
#include "Agachado.h"
#include "Caminando.h"

Parado::Parado() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Parado");
}

Parado::~Parado() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Parado");
}


void Parado::actualizar(Entidad * entidad) {
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);

    // TODO: Refactorizar
    if (entrada[SDL_SCANCODE_S]) { // Tecla S -> El personaje Salta
        EstadoDePersonaje* saltando = new Saltando();
        entidad->agregarComportamiento(saltando);
    }else if (entrada[SDL_SCANCODE_D]){
        EstadoDePersonaje* agachado = new Agachado();
        entidad->agregarComportamiento(agachado);
    } else if (entrada[SDL_SCANCODE_A]) {
//        EstadoDePersonaje* golpeando = new Golpeando();
//        entidad->agregarComportamiento(golpeando);
    } else if (entrada[SDL_SCANCODE_RIGHT] || entrada[SDL_SCANCODE_LEFT] || entrada[SDL_SCANCODE_DOWN] || entrada[SDL_SCANCODE_UP]){
        EstadoDePersonaje* caminando = new Caminando();
        entidad->agregarComportamiento(caminando);
    }
}
