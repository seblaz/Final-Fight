//
// Created by franco on 14/11/19.
//

#ifndef FINAL_FIGHT_GRAFICOELIMINABLE_H
#define FINAL_FIGHT_GRAFICOELIMINABLE_H


#include "Grafico.h"

class GraficoEliminable : public Grafico {

public:
    explicit GraficoEliminable(Entidad* entidad): Grafico(entidad){}

    void actualizar() override ;
};


#endif //FINAL_FIGHT_GRAFICOELIMINABLE_H
