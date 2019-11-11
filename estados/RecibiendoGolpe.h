//
// Created by franco on 3/11/19.
//

#ifndef FINAL_FIGHT_RECIBIENDOGOLPE_H
#define FINAL_FIGHT_RECIBIENDOGOLPE_H


#include "EstadoDePersonajeServidor.h"

class RecibiendoGolpe : public EstadoDePersonajeServidor{

public:
    RecibiendoGolpe();
    ~RecibiendoGolpe();

    void actualizar(Entidad *) override;
    void darGolpe(Entidad *) override {};
    void saltar(Entidad *) override {};
    void caminar(Entidad *, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) override {};
    void reposar(Entidad *) override {};
    void agachar(Entidad *) override {};
    void recibirGolpe(Entidad *) override {};
};


#endif //FINAL_FIGHT_RECIBIENDOGOLPE_H
