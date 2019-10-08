//
// Created by leandro on 7/10/19.
//

#ifndef FINAL_FIGHT_MANAGERUSUARIOS_H
#define FINAL_FIGHT_MANAGERUSUARIOS_H

#include <array>
#include "Usuario.h"

using namespace std;

class ManagerUsuarios {
    private:
        array<Usuario, 6> usuarios;
        int maximo;

    public:
        ManagerUsuarios(int maximo);
        void agregarUsuario(Usuario usuario);
        bool estaPresente(Usuario usuario);

};


#endif //FINAL_FIGHT_MANAGERUSUARIOS_H
