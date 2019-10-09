//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_CONFIRMARSELECCION_H
#define FINAL_FIGHT_CONFIRMARSELECCION_H


#include "Eventos.h"

class ConfirmarSeleccion : public EventoAProcesar {

private:
    Mapa *mapa;

public:
    explicit ConfirmarSeleccion(Mapa *mapa);
    void resolver() override;
};


#endif //FINAL_FIGHT_CONFIRMARSELECCION_H
