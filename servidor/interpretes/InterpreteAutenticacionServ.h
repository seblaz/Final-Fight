//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_INTERPRETEAUTENTICACIONSERV_H
#define FINAL_FIGHT_INTERPRETEAUTENTICACIONSERV_H


#include "InterpreteServidor.h"
#include "../modelo/ModeloAutenticacion.h"
#include "../etapas/ManagerEtapas.h"

class InterpreteAutenticacionServ : public InterpreteServidor {

private:
    bool validarContrasenia(Usuario *usuario);
    ModeloAutenticacion *autenticacion;
    ManagerEtapas *managerEtapas;
    semaphore usuarioAgregado = semaphore(0);

public:
    InterpreteAutenticacionServ(Usuario *usuario, ModeloAutenticacion *autenticacion, ManagerEtapas *managerEtapas);
    bool interpretarAccion(ACCION accion, stringstream &s) override;
};

class AgregarUsuario : public EventoAProcesar {

private:
    Usuario *usuario;
    semaphore &usuarioAgregado;
    ModeloAutenticacion *autenticacion;
    ManagerEtapas *etapas;

public:
    AgregarUsuario(Usuario *usuario, ModeloAutenticacion *autenticacion, semaphore &semaphore, ManagerEtapas *etapas);
    void resolver() override;

};
#endif //FINAL_FIGHT_INTERPRETEAUTENTICACIONSERV_H
