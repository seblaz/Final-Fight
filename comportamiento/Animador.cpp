//
// Created by franco on 23/9/19.
//

#include "Animador.h"
#include "../servicios/Locator.h"
#include "../modelo/Velocidad.h"
#include "../estados/Caminando.h"

void Animador::actualizar(Entidad *entidad) {

    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado");
    if (estado->cambioElEstado()) {
        enum ESTADO tipoEstado = estado->getNuevoEstado();
        auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
        if (tipoEstado == GOLPEANDO) {
            if( estado->getEstadoDePersonaje() == SALTANDO ){
                auto *animacion = fabricaDeAnimaciones->patadaBasica();
                entidad->agregarEstado("animacion", animacion);
            }else{
                auto *animacion = fabricaDeAnimaciones->golpear();
                entidad->agregarEstado("animacion", animacion);
            }
        } else if (tipoEstado == SALTANDO) {
            if( estado->getEstadoDePersonaje() == CAMINANDO ){
                auto *animacion = fabricaDeAnimaciones->saltandoAdelante();
                entidad->agregarEstado("animacion", animacion);
            }else{
                auto *animacion = fabricaDeAnimaciones->saltando();
                entidad->agregarEstado("animacion", animacion);
            }
        } else if (tipoEstado == AGACHADO) {
            auto *animacion = fabricaDeAnimaciones->agachado();
            entidad->agregarEstado("animacion", animacion);
        } else if ( tipoEstado == CAMINANDO ){
            auto *animacion = fabricaDeAnimaciones->caminando();
            entidad->agregarEstado("animacion", animacion);
        } else if ( tipoEstado == REPOSANDO ){
            auto *animacion = fabricaDeAnimaciones->reposando();
            entidad->agregarEstado("animacion", animacion);
        }

        estado -> consolidarEstados();
    }
}