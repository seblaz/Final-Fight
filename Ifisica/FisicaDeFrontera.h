//
// Created by sebas on 18/9/19.
//

#ifndef FINAL_FIGHT_FISICADEFRONTERA_H
#define FINAL_FIGHT_FISICADEFRONTERA_H


#include "Fisica.h"
#include "../fisica/FisicaDePersonaje.h"

class FisicaDeFrontera : public Fisica {

private:
    int largo_;
    FisicaDePersonaje *fisicaDePersonaje;

public:
    explicit FisicaDeFrontera(int largo, FisicaDePersonaje *fisicaDePersonaje);
    void actualizar() override;

};


#endif //FINAL_FIGHT_FISICADEFRONTERA_H
