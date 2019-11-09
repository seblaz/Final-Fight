//
// Created by franco on 31/10/19.
//

#include "Colisionables.h"
#include "Envolvente.h"
#include "../estados/EstadoDePersonajeServidor.h"
#include <utility>

Colisionables::Colisionables(unordered_map<IdEntidad, Entidad *>  colisionables) {
    this -> colisionables = std::move(colisionables);
}

void Colisionables::calcularPosiblesColisiones(Entidad * entidad) {
    auto* mapa = Locator::mapa();
    auto* envolvente= entidad->getEstado<Envolvente>("envolvente");

    auto* posicion = entidad->getEstado<Posicion>("posicion");
    for ( auto entidad_colisionable : mapa->devolverEntidades()){
        if ( entidad_colisionable != entidad && entidad_colisionable->getEstado<Envolvente>("envolvente") != nullptr) {
            auto* envolventeContrario = entidad_colisionable->getEstado<Envolvente>("envolvente");
            auto* velocidadContrario = entidad_colisionable->getEstado<Velocidad>("velocidad");
            auto *estado = entidad->getComportamiento<EstadoDePersonajeServidor>("estado");

            if ( velocidadContrario->x == 0 && velocidadContrario->y == 0){

                if (envolvente->existeColisionLeft(envolventeContrario) ){
                    posicion->x = envolventeContrario->posicion->x - envolventeContrario->ancho - envolvente->ancho;
                    //estado->golpear(entidad);
                }else if (envolvente->existeColisionRight(envolventeContrario) ){
                    posicion->x = envolventeContrario->posicion->x + envolventeContrario->ancho + envolvente->ancho;
                    //estado->golpear(entidad);
                }else if ( envolvente->existeColisionUp(envolventeContrario) ){
                    posicion->y = envolventeContrario->posicion->y + envolventeContrario->profundidad + envolvente->profundidad;
                    //estado->golpear(entidad);
                }else if ( envolvente->existeColisionDown(envolventeContrario)){
                    posicion->y = envolventeContrario->posicion->y - envolventeContrario->profundidad - envolvente->profundidad;
                    //estado->golpear(entidad);
                }
            }
        }
    }
}

void Colisionables::calcularPosiblesColisiones() {

    for ( auto entidadCentral : Locator::mapa()->devolverEntidades() ){
        auto* envolvente= entidadCentral->getEstado<Envolvente>("envolvente");
        auto* posicion = entidadCentral->getEstado<Posicion>("posicion");
        auto* velocidad = entidadCentral->getEstado<Velocidad>("velocidad");
        for ( auto entidad_colisionable : Locator::mapa()->devolverEntidades() ){

            if ( entidad_colisionable != entidadCentral && entidad_colisionable->getEstado<Envolvente>("envolvente") != nullptr
                    && entidadCentral->getEstado<Envolvente>("envolvente") != nullptr ) {
                auto *envolventeContrario = entidad_colisionable->getEstado<Envolvente>("envolvente");
                auto *velocidadContrario = entidad_colisionable->getEstado<Velocidad>("velocidad");
                auto *posicionContrario = entidad_colisionable->getEstado<Posicion>("posicion");

                if ( velocidadContrario->x == 0 && velocidad->x != 0){

                    if (envolvente->existeColisionLeft(envolventeContrario) ){
                        posicion->x = envolventeContrario->posicion->x - envolventeContrario->ancho - envolvente->ancho;
                    }else if (envolvente->existeColisionRight(envolventeContrario) ){
                        posicion->x = envolventeContrario->posicion->x + envolventeContrario->ancho + envolvente->ancho;
                    }
                }else if ( velocidadContrario->x != 0 && velocidad->x != 0 ){
                    if (envolvente->existeColisionLeft(envolventeContrario) ){
                        //posicion->x = envolventeContrario->posicion->x - envolventeContrario->ancho - envolvente->ancho;
                        posicion->x -= int(velocidad->x);
                        posicionContrario->x -= int(velocidadContrario->x);

                    }else if (envolvente->existeColisionRight(envolventeContrario) ){
                        //posicion->x = envolventeContrario->posicion->x + envolventeContrario->ancho + envolvente->ancho;
                        posicion->x -= int(velocidad->x);
                        posicionContrario->x -= int(velocidadContrario->x);
                    }
                }
                /*if ( envolvente->existeColisionUp(envolventeContrario) ){
                    posicion->y = envolventeContrario->posicion->y + envolventeContrario->profundidad + envolvente->profundidad;

                }else if ( envolvente->existeColisionDown(envolventeContrario)){
                    posicion->y = envolventeContrario->posicion->y - envolventeContrario->profundidad - envolvente->profundidad;

                }*/
            }
        }
    }
}

