//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_MOSTRARPANTALLADESELECCION_H
#define FINAL_FIGHT_MOSTRARPANTALLADESELECCION_H

#include "Eventos.h"

using namespace std;

class MostrarPantallaDeSeleccion : public EventoAProcesar {

public:
    void resolver(Mapa&) override;

};


#endif //FINAL_FIGHT_MOSTRARPANTALLADESELECCION_H
