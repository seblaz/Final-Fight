//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_MANAGERCLIENTES_H
#define FINAL_FIGHT_MANAGERCLIENTES_H


#include <list>
#include "Cliente.h"
#include "../etapas/Etapa.h"

using namespace std;

class ManagerClientes
{

private:
  list < Cliente * >clientes;
  IdEtapa etapaActual = "menu de seleccion";

public:
  void agregarCliente (Cliente * cliente);
  void cambiarTodosA (const IdEtapa & idEtapa);
  void quitarCliente (Cliente * cliente);
  IdEtapa getEtapaActual ();

};


#endif //FINAL_FIGHT_MANAGERCLIENTES_H
