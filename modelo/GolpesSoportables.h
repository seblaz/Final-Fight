//
// Created by franco on 11/11/19.
//

#ifndef FINAL_FIGHT_GOLPESSOPORTABLES_H
#define FINAL_FIGHT_GOLPESSOPORTABLES_H


#include "Entidad.h"

class GolpesSoportables : public Estado {

public:
    int maximoDeGolpes;

    explicit GolpesSoportables(int golpesMaximos);
    bool seRompio();
    void restarGolpe();
};


#endif //FINAL_FIGHT_GOLPESSOPORTABLES_H
