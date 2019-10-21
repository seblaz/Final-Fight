//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_REPOSANDO_H
#define FINAL_FIGHT_REPOSANDO_H


#include "EstadoDePersonajeServidor.h"

class Reposando : public EstadoDePersonajeServidor {

private:

public:
    Reposando();
    ~Reposando();
    void actualizar(Entidad *) override;
    void reposar(Entidad *) override {};
};

#endif //FINAL_FIGHT_REPOSANDO_H
