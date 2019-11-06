//
// Created by sebas on 6/11/19.
//

#ifndef FINAL_FIGHT_MENUSELECCION_H
#define FINAL_FIGHT_MENUSELECCION_H


#include "../../modelo/serializables/Personaje.h"

class MenuSeleccion {

private:
    enum PERSONAJE actual = CODY;
    bool listo_ = false;

public:
    enum PERSONAJE getPersonaje();
    void siguiente();
    void anterior();
    void confirmar();
    bool listo();

};


#endif //FINAL_FIGHT_MENUSELECCION_H
