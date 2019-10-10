//
// Created by leandro on 7/10/19.
//

#include "ManagerUsuarios.h"

ManagerUsuarios::ManagerUsuarios(int max) {
    maximo = max;
}

void ManagerUsuarios::agregarUsuario(Usuario nuevoUsuario) {
    if(usuarios.size() < maximo && !estaPresente(nuevoUsuario.getUsuario())){
        usuarios.push_back(nuevoUsuario);
    }else{
        throw exception();
    }
}

bool ManagerUsuarios::estaPresente(string usuario){
    bool encontrado = false;

    std::list<Usuario>::iterator it = usuarios.begin();

    while(usuarios.end() != it && !encontrado){
        encontrado = it->getUsuario() == usuario;
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

bool ManagerUsuarios::faltanJugadores() {
    return usuarios.size() < maximo;
}

int ManagerUsuarios::cantidadJugadoresFaltantes() {
    return maximo - usuarios.size();
}