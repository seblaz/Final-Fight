//
// Created by franco on 23/9/19.
//

#include "Animador.h"
#include "../estados/Caminando.h"
#include "../modelo/EstadoDePersonaje.h"

void Animador::actualizar(Entidad *entidad) {

    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado de personaje");
    auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
    switch (estado->getEstado()){
        case CAMINANDO:
            entidad->agregarEstado("animacion", fabricaDeAnimaciones->caminando());
            break;
        case SALTANDO:
            entidad->agregarEstado("animacion", fabricaDeAnimaciones->saltando());
            break;
        case REPOSANDO:
            entidad->agregarEstado("animacion", fabricaDeAnimaciones->reposando());
            break;
        case GOLPEANDO:
            entidad->agregarEstado("animacion", fabricaDeAnimaciones->golpear());
            break;
        case AGACHADO:
            entidad->agregarEstado("animacion", fabricaDeAnimaciones->agachado());
            break;
        case PATEANDO:
            entidad->agregarEstado("animacion", fabricaDeAnimaciones->patadaBasica());
            break;
        case SALTANDO_CON_MOVIMIENTO:
            entidad->agregarEstado("animacion", fabricaDeAnimaciones->saltandoAdelante());
            break;
    }
}