//
// Created by sebas on 5/11/19.
//

#include "ManagerEtapas.h"
#include "../../servicios/Locator.h"

void ManagerEtapas::agregar(Etapa *etapa) {
    if(!actual)
        actual = etapa;
    etapas[etapa->getId()] = etapa;
//    etapa->setManager(this);
}

Etapa *ManagerEtapas::getActual() {
    return actual;
}

void ManagerEtapas::cambiarA(const IdEtapa& id) {
//    etapas[id]->setUsuario(actual->getUsuario());
    actual = etapas[id];
    Locator::logger()->log(INFO, "Se cambia al usuario: " + actual->getInterprete()->getUsuario()->getUsuario() + " a la etapa: " + id + ".");
}
