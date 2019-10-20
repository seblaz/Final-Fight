//
// Created by leandro on 7/10/19.
//

#ifndef FINAL_FIGHT_MANAGERUSUARIOS_H
#define FINAL_FIGHT_MANAGERUSUARIOS_H

#include <array>
#include <list>
#include "Usuario.h"
#include "../eventos/semaphore.h"

using namespace std;

class ManagerUsuarios {

private:
    int maximo;
    list<Usuario *> usuarios;

public:
    explicit ManagerUsuarios(int maximo);

    bool faltanJugadores();
    list<Usuario *> getUsuarios();
    int cantidadJugadoresTotales();
    bool estaPresente(Usuario *usuario);
    void agregarUsuario(Usuario *usuario);
    void reemplazarUsuarioCon(Usuario *usuario);
    Usuario *getUsuarioAnterior(Usuario *usuario);
//    void administrarUsuario(Usuario *usuario);
//        int getCantidadLogueados();
//        bool faltanJugadores();
//        vector<Socket> getSockets();
//        void cambiarSocketParaUsuario(Usuario usuario, Socket* pSocket);
};


#endif //FINAL_FIGHT_MANAGERUSUARIOS_H
