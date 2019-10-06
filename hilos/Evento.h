//
// Created by sebas on 5/10/19.
//

#ifndef FINAL_FIGHT_EVENTO_H
#define FINAL_FIGHT_EVENTO_H

#include <string>
#include <utility>

using namespace std;

class Evento {

public:
    explicit Evento(string msg = "") : msg(std::move(msg)){}
    string msg;

};


#endif //FINAL_FIGHT_EVENTO_H
