//
// Created by sebas on 8/10/19.
//

#include "NivelCliente.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../graficos/GraficoDePantallaCompleta.h"
#include "../modelo/Posicion.h"
#include "../comportamiento/EntradaPantallaDeSeleccion.h"

void NivelCliente::generarPantallaDeEspera(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se genera el menu de seleccion.");
    Configuracion *config = Locator::configuracion();
    string srcSprite = config->getValue("/pantallaDeSeleccion/jugador1/seleccion/src");
    auto *renderer = Locator::renderer();

    Entidad *pantalla = mapa->crearEntidad();

    auto *sprite = new Sprite(renderer, srcSprite);
    auto *posicion = new Posicion(0, 0, 0);
    auto *grafico = new GraficoDePantallaCompleta();
    auto *entrada = new EntradaPantallaDeSeleccion();

    pantalla->agregarEstado("posicion", posicion);
    pantalla->agregarEstado("sprite", sprite);
    pantalla->agregarEstado("mapa", mapa);
    pantalla->agregarComportamiento("grafico", grafico);
    pantalla->agregarComportamiento("entrada", entrada);
}

void NivelCliente::generarMenuSeleccion(Mapa *mapa, Entidad *pantalla) {
    Locator::logger()->log(INFO, "Se genera el menu de seleccion.");
    Configuracion *config = Locator::configuracion();
    string srcSprite = config->getValue("/pantallaDeSeleccion/jugador1/seleccion/src");
    auto *renderer = Locator::renderer();
    auto *sprite = new Sprite(renderer, srcSprite);
    auto *grafico = new GraficoDePantallaCompleta();
//    auto *entrada = new EntradaPantallaDeSeleccion();
//    pantalla->agregarComportamiento("entrada", entrada);

    pantalla->agregarEstado("sprite", sprite);
    pantalla->agregarEstado("mapa", mapa);
    pantalla->agregarComportamiento("grafico", grafico);
}
