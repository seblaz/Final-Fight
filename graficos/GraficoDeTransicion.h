//
// Created by sebas on 23/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODETRANSICION_H
#define FINAL_FIGHT_GRAFICODETRANSICION_H


#include "../modelo/Entidad.h"

class GraficoDeTransicion : public Comportamiento {

public:
    void actualizar(Entidad *) override;
};


#endif //FINAL_FIGHT_GRAFICODETRANSICION_H
