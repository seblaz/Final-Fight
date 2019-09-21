//
// Created by franco on 8/9/19.
//

#include "Agachado.h"
#include "../servicios/Locator.h"
#include "../modelo/Velocidad.h"
#include "Saltando.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"

Agachado::Agachado() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Agachado");
}

Agachado::~Agachado() {
    Logger* logger = Locator::logger();
    logger -> log(DEBUG, "Se instancio un objeto de clase Agachado");
}

void Agachado::actualizar(Entidad *entidad) {
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);
    if ( entrada[SDL_SCANCODE_D] ){
//        Velocidad &velocidad = fisica->velocidad();
//        velocidad.x = 0;
//        velocidad.y = 0;
//        velocidad.z = 0;
        Velocidad *velocidad = entidad->getEstado<Velocidad>();
        velocidad->x = 0;
        velocidad->y = 0;
        velocidad->z = 0;
    }else if ( entrada[SDL_SCANCODE_S] ){
        EstadoDePersonaje* saltando = new Saltando();
        entidad->agregarComportamiento(saltando);
        saltando->enter(entidad);
    }else{
        EstadoDePersonaje* parado = new Parado();
        entidad->agregarComportamiento(parado);
        parado->enter(entidad);
    }
}

void Agachado::enter(Entidad *entidad) {
    auto* animacion = FabricaDeAnimacionesDeCody::agachado();
    entidad->agregarEstado(animacion);
}
