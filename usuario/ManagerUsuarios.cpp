//
// Created by leandro on 7/10/19.
//

#include "ManagerUsuarios.h"
#include "../servicios/Locator.h"
#include <algorithm>

ManagerUsuarios::ManagerUsuarios(int max) :
        maximo(max) {}

void ManagerUsuarios::agregarUsuario(Usuario *nuevoUsuario) {
    Locator::logger()->log(DEBUG, "Se agrega el usuario: " + nuevoUsuario->getUsuario());
    usuarios.push_back(nuevoUsuario);
    Locator::logger()->log(INFO, "Faltan " +  to_string(maximo - usuarios.size()) + " jugadores.");
}

bool ManagerUsuarios::estaPresente(Usuario *usuario) {
    auto pos = find_if(usuarios.begin(), usuarios.end(), [&usuario](Usuario *u) {
        return u->getUsuario() == usuario->getUsuario();
    });
    return pos != usuarios.end();
}

list<Usuario *> ManagerUsuarios::getUsuarios() {
    return usuarios;
}

int ManagerUsuarios::cantidadJugadoresTotales() {
    return maximo;
}

Usuario *ManagerUsuarios::getUsuarioAnterior(Usuario *usuario) {
    auto pos = find_if(usuarios.begin(), usuarios.end(), [&usuario](Usuario *u) {
        return u->getUsuario() == usuario->getUsuario();
    });
    return *pos;
}

void ManagerUsuarios::reemplazarUsuarioCon(Usuario *usuario) {
    auto pos = find_if(usuarios.begin(), usuarios.end(), [&usuario](Usuario *u) {
        return u->getUsuario() == usuario->getUsuario();
    });
    *pos = usuario;
}

bool ManagerUsuarios::faltanJugadores() {
    return usuarios.size() < maximo;
}

void ManagerUsuarios::desconectarJugadorVoluntariamente(Usuario *usuario) {
    auto pos = find_if(usuarios.begin(), usuarios.end(), [&usuario](Usuario *u) {
        return u->getUsuario() == usuario->getUsuario();
    });

    Usuario* pUsuario = pos.operator*();
    pUsuario->desconectarVoluntariamente();
}

bool ManagerUsuarios::hayJugadoresConectados(){
    int conectados = 0;

    std::list<Usuario*>::iterator it;
    for (it = usuarios.begin(); it != usuarios.end(); ++it){
        if(!it.operator*()->estaDesconectadoVoluntariamente()){
            conectados++;
        }
    }
    return conectados > 0;
}