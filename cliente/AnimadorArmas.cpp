//
// Created by franco on 13/11/19.
//

#include "AnimadorArmas.h"
#include "../modelo/serializables/Eliminado.h"
#include "../graficos/FabricaDeAnimacionesCliente.h"

AnimadorArmas::AnimadorArmas(Entidad *entidad) : Animador(entidad) {

}

void AnimadorArmas::actualizar() {
    auto* statusArma = entidad->getEstado<Eliminado>("eliminado");

    if ( statusArma->status() ){
        entidad->agregarEstado("animacion", FabricaDeAnimacionesCliente("/animaciones/objetos").getAnimacion("/eliminado"));
    }
}
