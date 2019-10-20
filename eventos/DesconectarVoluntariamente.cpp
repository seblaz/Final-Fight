//
// Created by leo on 20/10/19.
//

#include "DesconectarVoluntariamente.h"

DesconectarVoluntariamente::DesconectarVoluntariamente(ManagerUsuarios *managerUsuarios) : manager(managerUsuarios) {}

void DesconectarVoluntariamente::resolver() {
    manager->desconectarJugadorVoluntariamente();
}