//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_PERSONAJESTATE_H
#define FINAL_FIGHT_PERSONAJESTATE_H

#include "../mapeables/Personaje.h"
#include "../Input.h"

class PersonajeState{

private:

public:
    virtual void handleInput(Personaje& personaje, Input input);
    virtual void update(Personaje& personaje);

};

#endif //FINAL_FIGHT_PERSONAJESTATE_H
