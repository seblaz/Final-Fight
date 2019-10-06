//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_MOSTRARPANTALLADESELECCION_H
#define FINAL_FIGHT_MOSTRARPANTALLADESELECCION_H

#include "Eventos.h"
#include "../servidor/NivelServidor.h"

using namespace std;

class MostrarPantallaDeSeleccion : public EventoAProcesar {

private:
    Mapa * mapa;

public:
    explicit MostrarPantallaDeSeleccion(Mapa *mapa);
    void resolver() override;

};


#endif //FINAL_FIGHT_MOSTRARPANTALLADESELECCION_H
