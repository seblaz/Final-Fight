//
// Created by felipe on 12/10/19.
//

#ifndef FINAL_FIGHT_ENTRADASELECCIONPERSONAJE_H
#define FINAL_FIGHT_ENTRADASELECCIONPERSONAJE_H

#include <SDL_system.h>
#include "../modelo/Entidad.h"
#include "../servicios/Configuracion.h"
#include "../modelo/Personaje.h"

class EntradaSeleccionPersonaje : public Comportamiento {

private:
    int delay = 10;

public:

    int framesPorAccion = 20;
    int framesInactivo = 0;

    bool activo = true;

    void actualizar(Entidad *) override;

    void cambiarAlPersonajeAnterior(Entidad *pantalla,  Personaje *personajeMarcado);

    void cambiarAlPersonajeSiguiente(Entidad *pantalla, Personaje *personajeMarcado);
};


#endif //FINAL_FIGHT_ENTRADASELECCIONPERSONAJE_H
