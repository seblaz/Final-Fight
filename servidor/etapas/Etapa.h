//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_ETAPA_H
#define FINAL_FIGHT_ETAPA_H

#include <sstream>
#include "../../usuario/Usuario.h"
#include "../../modelo/serializables/Accion.h"
#include "../../eventos/Eventos.h"
#include "../../modelo/serializables/NombrePantalla.h"
#include "../interpretes/InterpreteServidor.h"
#include "../modelo/Modelo.h"

using namespace std;

typedef string IdEtapa;

class ManagerEtapas;

class Etapa {

private:
    IdEtapa id;
    Modelo *modelo;
    InterpreteServidor *interprete;

public:
    explicit Etapa(IdEtapa id, Modelo *modelo, InterpreteServidor *interprete);
    IdEtapa getId();
    void serializar(stringstream &s);
//    Modelo *getModelo();
    InterpreteServidor *getInterprete();

};

#endif //FINAL_FIGHT_ETAPA_H
