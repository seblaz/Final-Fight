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
        enum ESTADO tipoEstado = estado->getNuevoEstado();
        estado -> consolidarEstados();
        if (tipoEstado == GOLPEANDO) { // Tecla S -> El personaje Salta
            //estado->golpear(entidad);
            auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
            auto *animacion = fabricaDeAnimaciones->golpear();
            entidad->agregarEstado("animacion", animacion);

        } else if (tipoEstado == SALTANDO) {
            //estado->saltar(entidad);
            auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
            auto *animacion = fabricaDeAnimaciones->saltando();
            entidad->agregarEstado("animacion", animacion);
        } else if (tipoEstado == AGACHADO) {
            //estado->agachar(entidad);
            auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
            auto *animacion = fabricaDeAnimaciones->agachado();
            entidad->agregarEstado("animacion", animacion);
        } else if ( tipoEstado == CAMINANDO ){
            auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
            auto *animacion = fabricaDeAnimaciones->caminando();
            entidad->agregarEstado("animacion", animacion);
        } else if ( tipoEstado == REPOSANDO ){
            auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
            auto *animacion = fabricaDeAnimaciones->reposando();
            entidad->agregarEstado("animacion", animacion);
        }
       /* else {
            estado->reposar(entidad);
            auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
            auto *animacion = fabricaDeAnimaciones->reposando();
            entidad->agregarEstado("animacion", animacion);
        } */
    }
}