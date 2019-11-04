//
// Created by franco on 31/10/19.
//

#include "FisicaDeColisiones.h"
#include "../modelo/Envolvente.h"
#include "../modelo/Mapa.h"
#include "../modelo/serializables/Actividad.h"
#include "../modelo/serializables/Orientacion.h"

void FisicaDeColisiones::actualizar(Entidad * entidad) {

   auto colisionables = entidad->getEstado<Mapa>("mapa")->getColisionables();
   auto idEntidad = entidad->getEstado<Mapa>("mapa")->getIdEntidad(entidad);
   colisionables->calcularPosiblesColisiones(entidad, idEntidad);

}
