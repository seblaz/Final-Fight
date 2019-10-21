//
// Created by sebas on 21/10/19.
//

#ifndef FINAL_FIGHT_GRAFICOJUGADOR_H
#define FINAL_FIGHT_GRAFICOJUGADOR_H


#include "../modelo/Entidad.h"
#include "Grafico.h"

class GraficoJugador : public Grafico {

public:
    void actualizar(Entidad*) override;

};


#endif //FINAL_FIGHT_GRAFICOJUGADOR_H
