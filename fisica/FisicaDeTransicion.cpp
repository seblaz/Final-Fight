//
// Created by franco on 12/10/19.
//

#include "FisicaDeTransicion.h"
#include "../modelo/Posicion.h"
#include "../servicios/Locator.h"
#include "../servicios/Configuracion.h"
#include "../modelo/Opacidad.h"
#include "../modelo/Jugadores.h"

FisicaDeTransicion::FisicaDeTransicion(int anchoDeEscenario) {
    this->anchoDeEscenario = anchoDeEscenario;
    Configuracion* config = Locator::configuracion();
    framesPorTransicionInicial = config->getIntValue("/transicion/inicial/frames");
    framesFaltantesPorTranscionInicial = framesPorTransicionInicial;
    margenTransicionFinal = config->getIntValue("/transicion/final/margen");
};

void FisicaDeTransicion::actualizar(Entidad* entidad) {
    Configuracion *config = Locator::configuracion();
    int posicionDeJugadorX = entidad->getEstado<Jugadores>("posicion de jugadores")->getMayorX();
    auto* opacidad = entidad->getEstado<Opacidad>("opacidad");

    if ((anchoDeEscenario - posicionDeJugadorX) <= 0) {
        opacidad->setOpacidad(255);
    } else if ((anchoDeEscenario - posicionDeJugadorX) > 0 && (anchoDeEscenario - posicionDeJugadorX) < margenTransicionFinal) {
        int opacidadValue = int((float)0xff * (1.0 - ((float)anchoDeEscenario - (float)posicionDeJugadorX) / (float)margenTransicionFinal));
        opacidad->setOpacidad(opacidadValue);

    }

    if(framesFaltantesPorTranscionInicial > 0){
        int opacidadValue = int((float)0xff * ((float)framesFaltantesPorTranscionInicial / (float)framesPorTransicionInicial));
        opacidad->setOpacidad(opacidadValue);
        framesFaltantesPorTranscionInicial--;
    }
}

