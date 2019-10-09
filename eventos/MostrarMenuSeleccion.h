//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_MOSTRARMENUSELECCION_H
#define FINAL_FIGHT_MOSTRARMENUSELECCION_H

#include "Eventos.h"
#include "../servidor/NivelServidor.h"

using namespace std;

class MostrarMenuSeleccion : public EventoAProcesar {

private:
    Mapa * mapa;

public:
    explicit MostrarMenuSeleccion(Mapa *mapa);
    void resolver() override;

};


#endif //FINAL_FIGHT_MOSTRARMENUSELECCION_H
