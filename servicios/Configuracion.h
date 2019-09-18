//
// Created by sebas on 9/9/19.
//

#ifndef FINAL_FIGHT_CONFIGURACION_H
#define FINAL_FIGHT_CONFIGURACION_H


class Configuracion {

public:
    Configuracion(int anchoDePantalla, int alturaDePantalla, float velocidadDeJuego, float escalaDeGraficos, float inclinacionDeEscenario, float escalaEnAnchoDeEscenario);

    const int alturaDePantalla;
    const int anchoDePantalla;
    const float velocidadDeJuego;
    const float escalaDeGraficos;
    const float inclinacionDeEscenario;
    const float escalaEnAnchoDeEscenario;
};


#endif //FINAL_FIGHT_CONFIGURACION_H
