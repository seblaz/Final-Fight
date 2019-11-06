//
// Created by sebas on 5/11/19.
//

#include "Etapa.h"
#include "../../servicios/Locator.h"

#include <utility>


Etapa::Etapa(IdEtapa id, Modelo *modelo, InterpreteServidor *interprete) :
        id(id),
        modelo(modelo),
        interprete(interprete) {
    interprete->setEtapa(this);
}

IdEtapa Etapa::getId() {
    return id;
}

//Modelo *Etapa::getModelo() {
//    return modelo;
//}

InterpreteServidor *Etapa::getInterprete() {
    return interprete;
}

void Etapa::serializar(stringstream &s) {
    NombrePantalla nombre(id);
    nombre.serializar(s);
    modelo->serializar(s);
}

void Etapa::finalizarCliente() {
    interprete->finalizarCliente();
}

void Etapa::iniciar() {
    interprete->iniciar();
}

void Etapa::setManager(ManagerEtapas *manager_) {
    manager = manager_;
}

ManagerEtapas *Etapa::getManager() {
    return manager;
}
