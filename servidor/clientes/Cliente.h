//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_CLIENTE_H
#define FINAL_FIGHT_CLIENTE_H


#include "../etapas/ManagerEtapas.h"
#include "../../modelo/Hilo.h"

class Cliente : public Hilo {

private:
    ManagerEtapas etapas;
    Socket *socket;
    Usuario *usuario = new Usuario;
    bool fin = false;

protected:
    void recibirEnHilo();
    void transmitirEnHilo();

public:
    explicit Cliente(Socket *socket);
    void cambiarA(const IdEtapa& etapa);

};


#endif //FINAL_FIGHT_CLIENTE_H
