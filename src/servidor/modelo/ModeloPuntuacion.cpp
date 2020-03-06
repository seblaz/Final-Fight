//
// Created by sebas on 7/11/19.
//

#include "ModeloPuntuacion.h"
#include "../../servicios/Locator.h"
#include "../../modelo/serializables/Puntaje.h"

void ModeloPuntuacion::serializar(ostream &stream) {
    for(auto usuario : Locator::usuarios()->getUsuarios()){
        usuario->serializar(stream);
        usuario->getPersonaje()->getEstado<Puntaje>("puntaje")->serializar(stream);
    }
}
