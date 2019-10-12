//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_CONFIRMARSELECCION_H
#define FINAL_FIGHT_CONFIRMARSELECCION_H


#include "Eventos.h"
#include "../modelo/Personaje.h"

class ConfirmarSeleccion : public EventoAProcesar {

private:
    Mapa *mapa;
    enum PERSONAJE personajeSeleccionado;

public:
    explicit ConfirmarSeleccion(Mapa *mapa, enum PERSONAJE personaje);
    void resolver() override;
};


#endif //FINAL_FIGHT_CONFIRMARSELECCION_H
