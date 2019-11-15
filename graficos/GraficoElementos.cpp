//
// Created by franco on 14/11/19.
//

#include "GraficoElementos.h"
#include "../modelo/serializables/Elemento.h"

void GraficoElementos::actualizar() {
    if (!entidad->getEstado<Elemento>("elemento")->estaRoto())
        Grafico::actualizar();
}
