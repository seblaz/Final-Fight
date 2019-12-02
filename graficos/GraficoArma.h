//
// Created by sebas on 15/11/19.
//

#ifndef FINAL_FIGHT_GRAFICOARMA_H
#define FINAL_FIGHT_GRAFICOARMA_H


#include "Grafico.h"

class GraficoArma : public Grafico {

public:
    using Grafico::Grafico;
    void actualizar() override;

};


#endif //FINAL_FIGHT_GRAFICOARMA_H
