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

    bool activo = true;

    void actualizar(Entidad *) override;

    void cambiarSpriteAlAnterior(Entidad *pantalla, Configuracion *config, SDL_Renderer *renderer,
                                 Personaje *personajeMarcado) const;

    void cambiarSpriteAlSiguiente(Entidad *pantalla, Configuracion *config, SDL_Renderer *renderer,
                                  Personaje *personajeMarcado) const;
};


#endif //FINAL_FIGHT_ENTRADASELECCIONPERSONAJE_H
