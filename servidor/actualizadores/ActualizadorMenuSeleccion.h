//
// Created by sebas on 12/10/19.
//

#ifndef FINAL_FIGHT_ACTUALIZADORMENUSELECCION_H
#define FINAL_FIGHT_ACTUALIZADORMENUSELECCION_H

#include <sstream>
#include "../../modelo/serializables/Accion.h"
#include "../../eventos/Eventos.h"
#include "../../servicios/Locator.h"
#include "../SelectorPersonajes.h"
#include "../../usuario/Usuario.h"
#include "../../usuario/ManagerUsuarios.h"
#include "../../modelo/serializables/Personaje.h"

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
    explicit ConfirmarSeleccion(SelectorPersonajes *selector, Mapa *mapa, ManagerUsuarios *manager,
                                enum PERSONAJE personaje, Usuario *usuario, semaphore *confirmacion);
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
//    chrono::time_point<chrono::system_clock> ultimaRecepcion_;
    void interpretarStream(stringstream &s);
    void desconectarUsuario();
    bool fin();

public:
    ActualizadorMenuSeleccion(Mapa *mapa, EventosAProcesar *eventos, SelectorPersonajes *selector, Usuario *usuario,
                              ManagerUsuarios *manager, semaphore *confirmacion);
    void actualizarPersonaje();


};


#endif //FINAL_FIGHT_ACTUALIZADORMENUSELECCION_H
