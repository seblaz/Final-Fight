//
// Created by leandro on 7/10/19.
//

#include "ManagerUsuarios.h"
#include "../servicios/Locator.h"

ManagerUsuarios::ManagerUsuarios(int max) {
    maximo = max;
}

void ManagerUsuarios::agregarUsuario(Usuario nuevoUsuario) {
    if(usuarios.size() < maximo && !estaPresente(nuevoUsuario)){
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

int ManagerUsuarios::getCantidadLogueados() {
    return usuarios.size();
}

bool ManagerUsuarios::faltanJugadores() {
    return usuarios.size() < maximo;
}

int ManagerUsuarios::cantidadJugadoresFaltantes() {
    return maximo - usuarios.size();
}

vector<Socket> ManagerUsuarios::getSockets(){
    vector<Socket> conexiones;
    std::list<Usuario>::iterator it = usuarios.begin();

    do{
        int socket = it->getSocket()->getIntSocket();
        conexiones.emplace_back(socket);
        it.operator++();
    }
    while(usuarios.end() != it);

    return conexiones;
}

void ManagerUsuarios::cambiarSocketParaUsuario(string usuario, Socket* pSocket) {
    bool encontrado = false;

    std::list<Usuario>::iterator it = usuarios.begin();

    while(usuarios.end() != it && !encontrado){
        encontrado = it->getUsuario() == usuario;
    }

    it->setSocket(pSocket);

    Locator::logger()->log(INFO, "Se cambio socket para usuario " + it->getUsuario());
}
