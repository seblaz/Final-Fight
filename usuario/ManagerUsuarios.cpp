//
// Created by leandro on 7/10/19.
//

#include "ManagerUsuarios.h"

ManagerUsuarios::ManagerUsuarios(int max) {
    maximo = max;
}

void ManagerUsuarios::agregarUsuario(Usuario nuevoUsuario) {
    if(usuarios.size() < maximo){
        usuarios.push_back(nuevoUsuario);
    }else{
        throw exception();
    }
}

bool ManagerUsuarios::estaPresente(Usuario usuario){
    bool encontrado = false;

    std::list<Usuario>::iterator it = usuarios.begin();

    while(usuarios.end() != it && !encontrado){
        encontrado = it->getUsuario() == usuario.getUsuario();
    }

    return encontrado;
}

bool ManagerUsuarios::estaLogueado(Usuario usuario){
    bool encontrado = false;

    std::list<Usuario>::iterator it = usuarios.begin();

    while(usuarios.end() != it && !encontrado){
        encontrado = (it->getUsuario() == usuario.getUsuario() && it->getContrasenia() == usuario.getContrasenia());
    }

    return encontrado;
}

int ManagerUsuarios::getCantidadLogueados() {
    return usuarios.size();
}