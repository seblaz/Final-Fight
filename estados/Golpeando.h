//
// Created by franco on 24/9/19.
//

#ifndef FINAL_FIGHT_GOLPEANDO_H
#define FINAL_FIGHT_GOLPEANDO_H

#include "EstadoDePersonaje.h"

class Golpeando : public EstadoDePersonaje{

private:
    bool termine = false;
    int frame = 0;
    int frames_totales = 6;
public:
    Golpeando();
    ~Golpeando();

    void actualizar(Entidad *) override;
    void enter(Entidad *entidad) override;
    void golpear(Entidad *) override {}; // Agregar secuencia de Golpes
    void saltar(Entidad *) override ;
    void caminar(Entidad *, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) override ;
    void reposar(Entidad *) override ;
    void agachar(Entidad *) override ;
};
#endif //FINAL_FIGHT_GOLPEANDO_H
