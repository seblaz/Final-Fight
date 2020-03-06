//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETEAUTENTICADORCLI_H
#define FINAL_FIGHT_INTERPRETEAUTENTICADORCLI_H


#include "InterpreteCliente.h"
#include "../vistas/VistaAutenticador.h"
#include "../pantallas/ManagerPantallas.h"

class InterpreteAutenticadorCli : public InterpreteCliente {

private:
    Autenticador *autenticador;
    ManagerPantallas *pantallas;

public:
    explicit InterpreteAutenticadorCli(Autenticador *autenticador, ManagerPantallas *pantallas);
    void interpretar(stringstream &s) override;

};


#endif //FINAL_FIGHT_INTERPRETEAUTENTICADORCLI_H
