//
// Created by sebas on 21/10/19.
//

#ifndef FINAL_FIGHT_GRAFICOJUGADOR_H
#define FINAL_FIGHT_GRAFICOJUGADOR_H


static const int escalaVida = 3;

#include <SDL_render.h>
#include "../modelo/Entidad.h"
#include "Grafico.h"

class GraficoJugador : public Grafico {

private:
    int framesModulacion = 8;
    bool claro = true;
    void renderizarVidaDeJugador();
    void renderizarIndicadorDeJugador();
    void modularColor();

public:
    explicit GraficoJugador(Entidad *entidad);
    void actualizar() override;

};


#endif //FINAL_FIGHT_GRAFICOJUGADOR_H
