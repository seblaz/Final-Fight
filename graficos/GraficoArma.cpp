//
// Created by sebas on 15/11/19.
//

#include "GraficoArma.h"
#include "../modelo/serializables/Arma.h"

void GraficoArma::actualizar() {
    if(entidad->getEstado<Arma>("arma")->enElSuelo()) Grafico::actualizar();
}
