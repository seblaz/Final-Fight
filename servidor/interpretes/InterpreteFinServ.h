//
// Created by sebas on 8/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETEFINSERV_H
#define FINAL_FIGHT_INTERPRETEFINSERV_H


#include "InterpreteServidor.h"

class InterpreteFinServ : public InterpreteServidor {

public:
    using InterpreteServidor::InterpreteServidor;
    bool interpretarAccion(ACCION accion, stringstream &s) override;

};


#endif //FINAL_FIGHT_INTERPRETEFINSERV_H
