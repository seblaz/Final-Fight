//
// Created by franco on 14/11/19.
//

#ifndef FINAL_FIGHT_GRAFICOELEMENTOS_H
#define FINAL_FIGHT_GRAFICOELEMENTOS_H


#include "Grafico.h"

class GraficoElementos : public Grafico {

public:
    explicit GraficoElementos(Entidad* entidad): Grafico(entidad){}

    void actualizar() override ;
};


#endif //FINAL_FIGHT_GRAFICOELEMENTOS_H
