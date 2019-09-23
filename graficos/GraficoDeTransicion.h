//
// Created by sebas on 23/9/19.
//

#ifndef FINAL_FIGHT_GRAFICODETRANSICION_H
#define FINAL_FIGHT_GRAFICODETRANSICION_H


#include "../modelo/Entidad.h"

class GraficoDeTransicion : public Comportamiento {

private:
    int anchoDeEscenario;

public:
    explicit GraficoDeTransicion(int anchoDeEscenario);
    void actualizar(Entidad *) override;
};


#endif //FINAL_FIGHT_GRAFICODETRANSICION_H
