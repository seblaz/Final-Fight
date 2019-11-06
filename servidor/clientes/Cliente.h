//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_CLIENTE_H
#define FINAL_FIGHT_CLIENTE_H


#include "../etapas/ManagerEtapas.h"
#include "../../modelo/Hilo.h"

class ManagerClientes;

class Cliente : public Hilo {

private:
    ManagerEtapas etapas;
    Socket *socket;
    Usuario *usuario = new Usuario;
    bool fin = false;
    ManagerClientes *manager = nullptr;

protected:
    void recibirEnHilo();
    void transmitirEnHilo();

public:
    explicit Cliente(Socket *socket);
    void cambiarA(const IdEtapa& etapa);
    void setManager(ManagerClientes *manager);

};


#endif //FINAL_FIGHT_CLIENTE_H
