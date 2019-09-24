//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_SALTANDO_H
#define FINAL_FIGHT_SALTANDO_H

#include "EstadoDePersonaje.h"
#include "Parado.h"

#define LIMITE 35 // Limite del salto en altura

class Saltando : public EstadoDePersonaje {

private:
    int alturaMaxima_ = LIMITE; // Numero de prueba SUPER HARDCODE
    bool subiendo_ = true;
    bool termine = false;

public:
    Saltando();
    ~Saltando();
    void actualizar(Entidad *);
    void enter(Entidad *) override;
    void saltar(Entidad * entidad) override;
    void caminar(Entidad *, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg);
    void agachar(Entidad *) override;
    void reposar(Entidad *) override;
};


#endif //FINAL_FIGHT_SALTANDO_H
