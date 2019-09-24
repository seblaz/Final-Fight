//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_SALTANDO_H
#define FINAL_FIGHT_SALTANDO_H

#include "EstadoDePersonaje.h"
#include "Reposando.h"

#define LIMITE 35 // Limite del salto en altura

class Saltando : public EstadoDePersonaje {

private:
    bool termine = false;
    float frames = 0;
    const float velocidadInicial = 22;
    const float aceleracion = -1;

public:
    Saltando();
    ~Saltando();
    void actualizar(Entidad *) override;
    void enter(Entidad *) override;
    void saltar(Entidad * entidad) override {};
    void caminar(Entidad *, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) override;
    void agachar(Entidad *) override;
    void reposar(Entidad *) override;
};


#endif //FINAL_FIGHT_SALTANDO_H
