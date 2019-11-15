//
// Created by franco on 14/11/19.
//

#include "GraficoEliminable.h"
#include "../modelo/serializables/Eliminable.h"

void GraficoEliminable::actualizar() {
    if (! entidad->getEstado<Eliminable>("eliminado")->status() )
        Grafico::actualizar();
}
