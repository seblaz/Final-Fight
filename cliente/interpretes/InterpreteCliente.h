//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETECLIENTE_H
#define FINAL_FIGHT_INTERPRETECLIENTE_H

#include <sstream>
#include "../../modelo/serializables/Serializable.h"

using namespace std;

class InterpreteCliente {

public:
    virtual void interpretar(stringstream &s) = 0;

};


#endif //FINAL_FIGHT_INTERPRETECLIENTE_H
