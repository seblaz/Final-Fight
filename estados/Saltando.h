//
// Created by franco on 8/9/19.
//

#ifndef FINAL_FIGHT_SALTANDO_H
#define FINAL_FIGHT_SALTANDO_H

#include "EstadoDePersonajeServidor.h"
#include "Reposando.h"

#define LIMITE 35 // Limite del salto en altura

class Saltando : public EstadoDePersonajeServidor {

private:
    bool pateando = false;
    bool termine = false;
    float frames = 1;
    const float velocidadInicial = 25;
    const float aceleracion = -1;

public:
    Saltando();
    ~Saltando();
    void actualizar(Entidad *) override;
    void saltar(Entidad * entidad) override;
    void caminar(Entidad *, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) override;
    void agachar(Entidad *) override;
    void reposar(Entidad *) override;
    void golpear(Entidad *) override;
};


#endif //FINAL_FIGHT_SALTANDO_H
