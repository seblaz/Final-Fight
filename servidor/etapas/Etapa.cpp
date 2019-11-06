//
// Created by sebas on 5/11/19.
//

#include "Etapa.h"
#include "../../servicios/Locator.h"

#include <utility>


Etapa::Etapa(IdEtapa id, Modelo *modelo, InterpreteServidor *interprete) :
        id(std::move(id)),
        modelo(modelo),
        interprete(interprete) {
    modelo->setId(id);
}

IdEtapa Etapa::getId() {
    return id;
}

Modelo *Etapa::getModelo() {
    return modelo;
}

InterpreteServidor *Etapa::getInterprete() {
    return interprete;
}
