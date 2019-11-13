//
// Created by sebas on 23/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODETRANSICION_H
#define FINAL_FIGHT_GRAFICODETRANSICION_H


#include "../modelo/Entidad.h"

class GraficoDeTransicion : public Comportamiento {

public:
    GraficoDeTransicion(Entidad *entidad);

    void actualizar() override;
};


#endif //FINAL_FIGHT_GRAFICODETRANSICION_H
