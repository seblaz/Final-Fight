//
// Created by sebas on 12/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADOR_H
#define FINAL_FIGHT_ACTUALIZADOR_H

#include <sstream>

using namespace std;

class Actualizador {

public:
    virtual void interpretarStream(stringstream &s) = 0;
    virtual bool fin() = 0;

};


#endif //FINAL_FIGHT_ACTUALIZADOR_H
