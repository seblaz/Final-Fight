//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_SELECCIONARCODY_H
#define FINAL_FIGHT_SELECCIONARCODY_H


#include "Eventos.h"

class SeleccionarCody : public EventoAProcesar {

private:
    Mapa *mapa;

public:
    explicit SeleccionarCody(Mapa *mapa);
    void resolver() override;
};


#endif //FINAL_FIGHT_SELECCIONARCODY_H
