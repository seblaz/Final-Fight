//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_DEPIE_H
#define FINAL_FIGHT_DEPIE_H

#include "EstadosDePersonaje.h"
#include "Saltando.h"

class DePie : public EstadosDePersonaje{

private:

public:
    EstadosDePersonaje *manejarEntrada(Personaje& personaje, const Uint8* entrada) override;
    void actualizar(Personaje& personaje) override;
};

#endif //FINAL_FIGHT_DEPIE_H
