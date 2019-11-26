//
// Created by sebas on 26/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETEGAMEOVER_H
#define FINAL_FIGHT_INTERPRETEGAMEOVER_H


#include "InterpreteServidor.h"

class InterpreteGameOver : public InterpreteServidor {

public:
    using InterpreteServidor::InterpreteServidor;
    bool interpretarAccion(ACCION accion, stringstream &s) override;

};

class ConfirmarSeleccionGameOver : public EventoAProcesar {

public:
    void resolver() override;

};

#endif //FINAL_FIGHT_INTERPRETEGAMEOVER_H
