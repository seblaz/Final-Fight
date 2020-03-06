//
// Created by franco on 24/9/19.
//

#ifndef FINAL_FIGHT_DANDOGOLPE_H
#define FINAL_FIGHT_DANDOGOLPE_H

#include "EstadoDePersonajeServidor.h"

class DandoGolpe : public EstadoDePersonajeServidor{

public:
    using EstadoDePersonajeServidor::EstadoDePersonajeServidor;

    void actualizar() override;
    void darGolpe() override {}; // Agregar secuencia de Golpes
    void saltar() override {};
    void caminar(bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) override {};
    void reposar() override {};
    void agachar() override {};
};
#endif //FINAL_FIGHT_DANDOGOLPE_H
