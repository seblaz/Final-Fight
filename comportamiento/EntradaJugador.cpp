//
// Created by franco on 23/9/19.
//

#include "EntradaJugador.h"
#include "../servicios/Locator.h"
#include "../modelo/Velocidad.h"
#include "../estados/Caminando.h"


#define RAPIDEZ 4

enum DIRECCION { IZQUIERDA = -1, DERECHA = 1, REPOSO = 0 };

void EntradaJugador::actualizar(Entidad * entidad) {
    //float velocidadRelativa = Locator::configuracion()->getFloatValue("/velocidad/juego");
    //auto* velocidad = entidad->getEstado<Velocidad>("velocidad");
    const Uint8 *entrada = SDL_GetKeyboardState(nullptr);
/*
    velocidad->x = 0;
    velocidad->y = 0;

    velocidad->x = RAPIDEZ * velocidadRelativa * entrada[SDL_SCANCODE_RIGHT];
    velocidad->x -= RAPIDEZ * velocidadRelativa * entrada[SDL_SCANCODE_LEFT];
    velocidad->y = RAPIDEZ * velocidadRelativa * entrada[SDL_SCANCODE_UP];
    velocidad->y -= RAPIDEZ * velocidadRelativa * entrada[SDL_SCANCODE_DOWN];*/
    auto* estado = entidad -> getComportamiento<EstadoDePersonaje>("estado");
    if (entrada[SDL_SCANCODE_S]) { // Tecla S -> El personaje Salta
        estado->saltar(entidad);
    }else if (entrada[SDL_SCANCODE_D]){
        //estado -> golpear(entidad);
    }
    else if (entrada[SDL_SCANCODE_RIGHT] ) {
      //  estado ->caminar(entidad, DERECHA, REPOSO); // caminar(entidad, direccion_X)
    }
    else if (entrada[SDL_SCANCODE_LEFT] ) {
       // estado ->caminar(entidad, IZQUIERDA, REPOSO); // caminar(entidad, direccion_X)
    }
}

