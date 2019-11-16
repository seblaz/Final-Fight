//
// Created by sebas on 16/11/19.
//

#ifndef FINAL_FIGHT_RECIBIENDOGOLPEELEMENTO_H
#define FINAL_FIGHT_RECIBIENDOGOLPEELEMENTO_H


#include "EstadoDeElemento.h"

class RecibiendoGolpeElemento : public EstadoDeElemento {

private:
    int framesFaltantes = 15;

public:
    using EstadoDeElemento::EstadoDeElemento;
    void actualizar() override;
    void recibirGolpeDe(Entidad *jugador) override {};

};


#endif //FINAL_FIGHT_RECIBIENDOGOLPEELEMENTO_H
