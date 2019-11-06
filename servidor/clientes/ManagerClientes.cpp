//
// Created by sebas on 5/11/19.
//

#include "ManagerClientes.h"

void ManagerClientes::cambiarTodosA(const IdEtapa &idEtapa) {
    for (auto cliente : clientes)
        cliente->cambiarA(idEtapa);
}

void ManagerClientes::agregarCliente(Cliente *cliente) {
    clientes.push_back(cliente);
}
