//
// Created by sebas on 16/11/19.
//

#include "RecibiendoGolpeElemento.h"
#include "Sano.h"

void RecibiendoGolpeElemento::actualizar() {
    if(framesFaltantes-- < 1) entidad->agregarComportamiento("estado", new Sano(entidad));
}
