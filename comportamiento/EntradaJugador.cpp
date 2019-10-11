//
// Created by franco on 23/9/19.
//

#include "EntradaJugador.h"
#include "../servicios/Locator.h"
#include "../modelo/Velocidad.h"
#include "../estados/Caminando.h"


#define RAPIDEZ 4

void EntradaJugador::actualizar(Entidad *entidad) {
    //const Uint8 *entrada = SDL_GetKeyboardState(nullptr);

    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado");
    //estado->actualizar(entidad);
    if (estado->cambioElEstado()) {
        string tipoEstado = estado->getNuevoEstado();
        estado -> consolidarEstados();
        if (tipoEstado == "golpeando") { // Tecla S -> El personaje Salta
            //estado->golpear(entidad);
            auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
            auto *animacion = fabricaDeAnimaciones->golpear();
            entidad->agregarEstado("animacion", animacion);

        } else if (tipoEstado == "saltando") {
            //estado->saltar(entidad);
            auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
            auto *animacion = fabricaDeAnimaciones->saltando();
            entidad->agregarEstado("animacion", animacion);
        } else if (tipoEstado == "agachando") {
            //estado->agachar(entidad);
            auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
            auto *animacion = fabricaDeAnimaciones->agachado();
            entidad->agregarEstado("animacion", animacion);
        } /*else if (entrada[SDL_SCANCODE_RIGHT] || entrada[SDL_SCANCODE_LEFT] || entrada[SDL_SCANCODE_DOWN] ||
               entrada[SDL_SCANCODE_UP]) {
        if (entrada[SDL_SCANCODE_RIGHT] && entrada[SDL_SCANCODE_LEFT]) {
            estado->reposar(entidad);
        } else if (entrada[SDL_SCANCODE_DOWN] && entrada[SDL_SCANCODE_UP]) {
            estado->reposar(entidad);
        } else {
            estado->caminar(entidad, entrada[SDL_SCANCODE_RIGHT], entrada[SDL_SCANCODE_LEFT], entrada[SDL_SCANCODE_UP],
                            entrada[SDL_SCANCODE_DOWN]);
        }
        }*/
        else {
            estado->reposar(entidad);
            auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
            auto *animacion = fabricaDeAnimaciones->caminando();
            entidad->agregarEstado("animacion", animacion);
        }
    }
}