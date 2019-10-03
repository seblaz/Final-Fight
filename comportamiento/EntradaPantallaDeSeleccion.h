//
// Created by sebas on 3/10/19.
//

#ifndef FINAL_FIGHT_ENTRADAPANTALLADESELECCION_H
#define FINAL_FIGHT_ENTRADAPANTALLADESELECCION_H


#include "../modelo/Entidad.h"

class EntradaPantallaDeSeleccion : public Comportamiento {

private:
    int delay = 10;

public:
    void actualizar(Entidad*) override;

};


#endif //FINAL_FIGHT_ENTRADAPANTALLADESELECCION_H
