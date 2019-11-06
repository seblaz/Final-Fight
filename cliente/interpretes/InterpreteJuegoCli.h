//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETEJUEGOCLI_H
#define FINAL_FIGHT_INTERPRETEJUEGOCLI_H


#include "InterpreteCliente.h"

class InterpreteJuegoCli : public InterpreteCliente {

public:
    void interpretar(stringstream &s) override;

};


#endif //FINAL_FIGHT_INTERPRETEJUEGOCLI_H
