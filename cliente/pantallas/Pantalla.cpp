//
// Created by sebas on 1/11/19.
//

#include "Pantalla.h"

#include <utility>
#include "ManagerPantallas.h"
#include "../../modelo/serializables/Modelo.h"

Pantalla::Pantalla(IdPantalla id, InterpreteCliente *interprete, EntradaUsuario *entradaUsuario, Vista *vista) :
        vista(vista),
        id(id),
        interprete(interprete),
        entradaUsuario(entradaUsuario) {}

IdPantalla Pantalla::getId() {
    return id;
}

void Pantalla::setManager(ManagerPantallas *manager_) {
    manager = manager_;
}

void Pantalla::interpretar(stringstream &s) {
    Modelo modelo;
    modelo.deserializar(s);
    manager->cambiarA(modelo.getId());
    interprete->interpretar(s);
}

void Pantalla::graficar(SDL_Renderer *renderer) {
    vista->graficar(renderer);
}

Accion *Pantalla::getAccion(SDL_Event *e) {
    return entradaUsuario->getAccion(e);
}
