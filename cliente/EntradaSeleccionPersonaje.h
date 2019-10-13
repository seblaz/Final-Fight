//
// Created by felipe on 12/10/19.
//

#ifndef FINAL_FIGHT_ENTRADASELECCIONPERSONAJE_H
#define FINAL_FIGHT_ENTRADASELECCIONPERSONAJE_H

#include "../modelo/Entidad.h"

class EntradaSeleccionPersonaje : public Comportamiento {

private:
      int delay = 10;

public:
    void actualizar(Entidad* ) override;
};


#endif //FINAL_FIGHT_ENTRADASELECCIONPERSONAJE_H
