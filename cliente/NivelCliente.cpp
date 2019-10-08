//
// Created by sebas on 8/10/19.
//

#include "NivelCliente.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../graficos/GraficoDePantallaCompleta.h"
#include "../modelo/Posicion.h"
#include "EntradaPantallaDeSeleccionNuevo.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeCody.h"
#include "../graficos/Grafico.h"

void NivelCliente::generarPantallaDeEspera(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se genera el menu de seleccion.");
    Configuracion *config = Locator::configuracion();
    string srcSprite = config->getValue("/pantallaDeSeleccion/jugador1/seleccion/src");
    auto *renderer = Locator::renderer();

    Entidad *pantalla = mapa->crearEntidad();

    auto *sprite = new Sprite(renderer, srcSprite);
    auto *posicion = new Posicion(0, 0, 0);
    auto *grafico = new GraficoDePantallaCompleta();

    pantalla->agregarEstado("posicion", posicion);
    pantalla->agregarEstado("sprite", sprite);
    pantalla->agregarEstado("mapa", mapa);
    pantalla->agregarComportamiento("grafico", grafico);
}

void NivelCliente::generarMenuSeleccion(Mapa *mapa, Entidad *pantalla) {
    Locator::logger()->log(INFO, "Se genera el menu de seleccion.");
    Configuracion *config = Locator::configuracion();
    string srcSprite = config->getValue("/pantallaDeSeleccion/jugador1/seleccion/src");
    auto *renderer = Locator::renderer();
    auto *sprite = new Sprite(renderer, srcSprite);
    auto *grafico = new GraficoDePantallaCompleta();
    auto *entrada = new EntradaPantallaDeSeleccionNuevo();

    pantalla->agregarEstado("sprite", sprite);
    pantalla->agregarEstado("mapa", mapa);
    pantalla->agregarComportamiento("grafico", grafico);
    pantalla->agregarComportamiento("entrada", entrada);
}

void NivelCliente::generarJugador(Mapa *mapa, IdEntidad idEntidad, Entidad *jugador) {
    Locator::logger()->log(INFO, "Se genera jugador.");
    SDL_Renderer *sdlRenderer = Locator::renderer();

    auto *fabricaDeAnimaciones = new FabricaDeAnimacionesDeCody();
    auto *spriteJugador = new Sprite(sdlRenderer, "assets/personajes/cody.png");
    auto *animacion = fabricaDeAnimaciones->reposando();
//    EstadoDePersonaje *estado = new Reposando();
    auto *grafico = new Grafico();
//    auto *entradaJugador = new EntradaJugador();

    jugador->agregarEstado("sprite", spriteJugador);
    jugador->agregarEstado("animacion", animacion);
//    jugador->agregarEstado("estado", estado);
    jugador->agregarEstado("fabrica de animaciones", fabricaDeAnimaciones);
    jugador->agregarComportamiento("grafico", grafico);
//    jugador->agregarComportamiento("entrada jugador", entradaJugador);
}
