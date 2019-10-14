//
// Created by sebas on 12/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADORMENUSELECCION_H
#define FINAL_FIGHT_ACTUALIZADORMENUSELECCION_H

#include <sstream>
#include "../../modelo/Accion.h"
#include "../../eventos/Eventos.h"
#include "../../servicios/Locator.h"
#include "../SelectorPersonajes.h"
#include "../../usuario/Usuario.h"
#include "../../usuario/ManagerUsuarios.h"

using namespace std;

class ConfirmarSeleccion : public EventoAProcesar {

private:
    Mapa *mapa;
    ManagerUsuarios *manager;
    SelectorPersonajes *selector;
    semaphore *confirmacion;
    Usuario *usuario;
    enum PERSONAJE personajeSeleccionado;

public:
    explicit ConfirmarSeleccion(SelectorPersonajes *selector, Mapa *mapa, ManagerUsuarios *manager, enum PERSONAJE personaje, Usuario *usuario,
                                semaphore *confirmacion);
    void resolver() override;
};

class ActualizadorMenuSeleccion {

private:
    bool fin_ = false;
    Mapa *mapa;
    Usuario *usuario;
    EventosAProcesar *eventos;
    SelectorPersonajes *selector;
    semaphore *confirmacion;
    ManagerUsuarios *manager;

public:
    ActualizadorMenuSeleccion(Mapa *mapa, EventosAProcesar *eventos, SelectorPersonajes *selector, Usuario *usuario,
                              ManagerUsuarios *manager, semaphore *confirmacion);
    void interpretarStream(stringstream &s);
    bool personajeFueEligidoPorOtroUsuario(enum PERSONAJE personajeABuscar);
    bool fin();

};


#endif //FINAL_FIGHT_ACTUALIZADORMENUSELECCION_H
