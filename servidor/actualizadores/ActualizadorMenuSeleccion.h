//
// Created by sebas on 12/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADORMENUSELECCION_H
#define FINAL_FIGHT_ACTUALIZADORMENUSELECCION_H

#include <sstream>
#include "Actualizador.h"
#include "../../modelo/Accion.h"
#include "../../eventos/Eventos.h"
#include "../../eventos/ConfirmarSeleccion.h"
#include "../../servicios/Locator.h"

using namespace std;

class ActualizadorMenuSeleccion : public Actualizador {

private:
    bool fin_ = false;
    Mapa *mapa;
    EventosAProcesar *eventos;

public:
    ActualizadorMenuSeleccion(Mapa *mapa, EventosAProcesar *eventos);
    void interpretarStream(stringstream &s) override;
    bool fin() override;

};


#endif //FINAL_FIGHT_ACTUALIZADORMENUSELECCION_H
