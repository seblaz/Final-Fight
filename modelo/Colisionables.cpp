//
// Created by franco on 31/10/19.
//

#include "Colisionables.h"
#include "Envolvente.h"
#include "serializables/Orientacion.h"
#include "serializables/NumeroJugador.h"

#include <utility>

Colisionables::Colisionables(unordered_map<IdEntidad, Entidad *>  colisionables) {
    this -> colisionables = std::move(colisionables);
}

void Colisionables::calcularPosiblesColisiones(Entidad * entidad, IdEntidad idEntidad) {
    auto* envolvente= entidad->getEstado<Envolvente>("envolvente");
    auto* posicion = entidad->getEstado<Posicion>("posicion");
    for ( auto tuple : colisionables){
        if ( tuple.first != idEntidad && tuple.second->getEstado<Envolvente>("envolvente") != nullptr){
            auto* envolventeContrario = tuple.second->getEstado<Envolvente>("envolvente");

            if (envolvente->existeColisionLeft(envolventeContrario) )
                posicion->x = envolventeContrario->posicion->x - envolventeContrario->ancho ;

            if (envolvente->existeColisionRight(envolventeContrario) )
                posicion->x = envolventeContrario->posicion->x + envolventeContrario->ancho;

            if ( envolvente->existeColisionUp(envolventeContrario) )
                posicion->y = envolventeContrario->posicion->y + envolventeContrario->profundidad + envolvente->profundidad;

            if ( envolvente->existeColisionDown(envolventeContrario))
                posicion->y = envolventeContrario->posicion->y - envolventeContrario->profundidad - envolvente->profundidad;

        }
    }
}

