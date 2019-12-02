//
// Created by sebas on 5/11/19.
//

#include "ManagerEtapas.h"
#include "../../servicios/Locator.h"

void ManagerEtapas::agregar(Etapa *etapa) {
    if(!actual)
        actual = etapa;
    etapas[etapa->getId()] = etapa;
    etapa->setManager(this);
}

Etapa *ManagerEtapas::getActual() {
    std::unique_lock<std::mutex> lock(m);
    return actual;
}

void ManagerEtapas::cambiarA(const IdEtapa& id) {
    {
        std::unique_lock<std::mutex> lock(m);
        actual = etapas[id];
        actual->iniciar();
    }
    Locator::logger()->log(INFO, "Se cambia al usuario: " + actual->getInterprete()->getUsuario()->getUsuario() + " a la etapa: " + id + ".");
}
