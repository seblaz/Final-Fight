//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_STANDING_H
#define FINAL_FIGHT_STANDING_H

#include "PersonajeState.h"

class Standing : public PersonajeState{

private:

public:
    virtual void handleInput(Personaje& personaje, Input input);
    virtual void update(Personaje& personaje);
};

#endif //FINAL_FIGHT_STANDING_H
