//
// Created by felipe on 12/10/19.
//

#ifndef FINAL_FIGHT_ENTRADASELECCIONPERSONAJE_H
#define FINAL_FIGHT_ENTRADASELECCIONPERSONAJE_H

#include "../modelo/Entidad.h"
#include "../servicios/Configuracion.h"
#include "../modelo/Personaje.h"

class EntradaSeleccionPersonaje : public Comportamiento {

public:

    int framesPorAccion = 7;
    int framesInactivo = 0;

    bool activo = true;

    void actualizar(Entidad *) override;
    void cambiarAlPersonajeAnterior(Entidad *pantalla,  Personaje *personajeMarcado);
    void cambiarAlPersonajeSiguiente(Entidad *pantalla, Personaje *personajeMarcado);
};


#endif //FINAL_FIGHT_ENTRADASELECCIONPERSONAJE_H
