//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_PARADO_H
#define FINAL_FIGHT_PARADO_H

#include "EstadoDePersonaje.h"
#include "Saltando.h"


class Parado : public EstadoDePersonaje{

private:

public:
    Parado();
    ~Parado() override;
    EstadoDePersonaje *manejarEntrada(FisicaDePersonaje *fisica, const Uint8* entrada) override;
    void actualizar() override {};
    void enter() override {};
    Animacion* devolverAnimacion(FabricaDeAnimacionesDeCody *fabrica);
};

#endif //FINAL_FIGHT_PARADO_H
