//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_EVENTO_H
#define FINAL_FIGHT_EVENTO_H

#include <string>
#include <utility>
#include <cstdarg>

using namespace std;

void accionNula();

class Evento {

private:
    void (*accion)();

public:
    explicit Evento(string msg = "", void (*accion)() = accionNula);
    void resolver();
    string msg;

};

#endif //FINAL_FIGHT_EVENTO_H
