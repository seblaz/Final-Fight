//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_SALTANDO_H
#define FINAL_FIGHT_SALTANDO_H

#include "EstadoDePersonaje.h"
#include "Parado.h"

#define LIMITE 30 // Limite del salto en altura

class Saltando : public EstadoDePersonaje {

private:
    int alturaMaxima_ = LIMITE; // Numero de prueba SUPER HARDCODE
    bool subiendo_ = true;

public:
    Saltando();
    ~Saltando();
    void actualizar(Entidad *) override;
};

#endif //FINAL_FIGHT_SALTANDO_H
