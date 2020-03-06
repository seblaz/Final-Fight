//
// Created by franco on 15/11/19.
//

#ifndef FINAL_FIGHT_MUERTO_H
#define FINAL_FIGHT_MUERTO_H


#include "EstadoDePersonajeServidor.h"

class Muerto : public EstadoDePersonajeServidor {

public:
    using EstadoDePersonajeServidor::EstadoDePersonajeServidor;

    void actualizar() override;
    void darGolpe() override {};
    void saltar() override {};
    void caminar(bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) override {};
    void reposar() override {};
    void agachar() override {};
    void recibirGolpeDe(Entidad* golpeador) override {};
};


#endif //FINAL_FIGHT_MUERTO_H
