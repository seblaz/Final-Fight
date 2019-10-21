//
// Created by leo on 20/10/19.
//

#include "DesconectarVoluntariamente.h"

DesconectarVoluntariamente::DesconectarVoluntariamente(ManagerUsuarios *managerUsuarios, Usuario* usuario) :
    manager(managerUsuarios),
    usuario(usuario) {}

void DesconectarVoluntariamente::resolver() {
    manager->desconectarJugadorVoluntariamente(usuario);
}