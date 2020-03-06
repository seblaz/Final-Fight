//
// Created by sebas on 21/10/19.
//

#ifndef FINAL_FIGHT_GRAFICOJUGADOR_H
#define FINAL_FIGHT_GRAFICOJUGADOR_H


static const int escalaVida = 3;

#include <SDL_render.h>
#include "../modelo/Entidad.h"
#include "Grafico.h"
#include "../modelo/serializables/Puntaje.h"
#include "../modelo/serializables/NumeroJugador.h"

class GraficoJugador : public Grafico {

private:
    int framesModulacion = 8;
    bool claro = true;
    void renderizarVidaDeJugador();
    void renderizarIndicadorDeJugador();
    void renderizarPuntosDeJugador(Puntaje* puntaje, NumeroJugador* numeroJugador);
    void modularColor();

public:
    explicit GraficoJugador(Entidad *entidad);
    void actualizar() override;


};


#endif //FINAL_FIGHT_GRAFICOJUGADOR_H
