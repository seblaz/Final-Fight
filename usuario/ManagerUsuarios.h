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
    semaphore juegoListo;
    list<Usuario *> usuarios;
    void agregarUsuario(Usuario *usuario);

public:
    explicit ManagerUsuarios(int maximo);
    void administrarUsuario(Usuario *usuario);
    bool estaPresente(Usuario *usuario);
    int cantidadJugadoresFaltantes();
    void esperarUsuarios();
    list<Usuario *> getUsuarios();
    int cantidadJugadoresTotales();
//        int getCantidadLogueados();
//        bool faltanJugadores();
//        vector<Socket> getSockets();
//        void cambiarSocketParaUsuario(Usuario usuario, Socket* pSocket);
};


#endif //FINAL_FIGHT_MANAGERUSUARIOS_H
