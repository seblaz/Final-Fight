//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETEJUEGOSERV_H
#define FINAL_FIGHT_INTERPRETEJUEGOSERV_H


#include "InterpreteServidor.h"

class InterpreteJuegoServ : public InterpreteServidor {

public:
    using InterpreteServidor::InterpreteServidor;
    bool interpretarAccion(ACCION accion, stringstream &s) override;

};


#endif //FINAL_FIGHT_INTERPRETEJUEGOSERV_H
