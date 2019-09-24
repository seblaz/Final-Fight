//
// Created by franco on 6/9/19.
//

#ifndef FINAL_FIGHT_REPOSANDO_H
#define FINAL_FIGHT_REPOSANDO_H


#include "EstadoDePersonaje.h"

class Reposando : public EstadoDePersonaje {

private:

public:
    Reposando();
    ~Reposando();
    void enter(Entidad *) override;
    void actualizar(Entidad *) override;
    void reposar(Entidad *) override {};
};

#endif //FINAL_FIGHT_REPOSANDO_H
