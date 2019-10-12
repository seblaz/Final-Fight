//
// Created by sebas on 6/10/19.
//

#include "NivelServidor.h"
#include "../modelo/Nivel.h"
#include "../estados/Reposando.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../fisica/FisicaDeEscenario.h"

void NivelServidor::generarMenuSeleccion(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se genera el menu de seleccion.");

    Entidad *pantalla = mapa->crearEntidad();
    auto *posicion = new Posicion(0, 10, 0);
    auto *tipo = new Tipo(PANTALLA_SELECCION);

    pantalla->agregarEstado("posicion", posicion);
    pantalla->agregarEstado("mapa", mapa);
    pantalla->agregarEstado("tipo", tipo);
}

void NivelServidor::generarPersonajesSeleccion(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se generan los personajes de seleccion.");

    Entidad *personajeDeSeleccion = mapa->crearEntidad();
    auto *posicion = new Posicion(0, 0, 0);
    auto *personaje = new Personaje(CODY);
    auto *tipo = new Tipo(PERSONAJE_SELECCION);

    personajeDeSeleccion->agregarEstado("posicion", posicion);
    personajeDeSeleccion->agregarEstado("tipo", tipo);
    personajeDeSeleccion->agregarEstado("personaje", personaje);
}

void NivelServidor::generarJugador(Mapa *mapa, enum PERSONAJE personajeSeleccionado) {
    Locator::logger()->log(INFO, "Se genera jugador.");

    switch (personajeSeleccionado){
        case HAGGAR:
            Locator::logger()->log(DEBUG,"Se selecciono Haggar");
            break;
        case CODY:
            Locator::logger()->log(DEBUG,"Se selecciono Coddy");
            break;
    }

    auto* jugador = mapa->crearJugador();
    auto* posicion = new Posicion(200, 100, 0);
    auto *velocidad = new Velocidad();
    auto *orientacion = new Orientacion;
    auto *tipo = new Tipo(JUGADOR);
    auto *personaje = new Personaje(personajeSeleccionado);
    EstadoDePersonaje *estado = new Reposando();
    auto *fisica = new FisicaDePersonaje();

    jugador->agregarEstado("tipo", tipo);
    jugador->agregarEstado("posicion", posicion);
    jugador->agregarEstado("velocidad", velocidad);
    jugador->agregarEstado("orientacion", orientacion);
    jugador->agregarEstado("estado", estado);
    jugador->agregarEstado("personaje", personaje);
    jugador->agregarComportamiento("estado", estado);
    jugador->agregarComportamiento("fisica", fisica);
}

void NivelServidor::generarNivel(const string &nivel, Mapa *mapa) {
    Locator::logger()->log(DEBUG, "Se genera " + nivel);

    Entidad *escenario = generarEscenario(nivel, mapa);

    /**
     * Dependencias.
     */
    Entidad *jugador = mapa->getJugador();
    auto *posicionDeJugador = jugador->getEstado<Posicion>("posicion");
    auto *posicionDeEscenario = escenario->getEstado<Posicion>("posicion");
    escenario->agregarEstado("posicion de jugador", posicionDeJugador);
    jugador->agregarEstado("posicion de escenario", posicionDeEscenario);
    posicionDeJugador->x = 200;
    posicionDeJugador->y = 100;

//    generarCajas(nivel, sdlRenderer, mapa, posicionDeEscenario);
//    generarNeumaticos(nivel, sdlRenderer, mapa, posicionDeEscenario);
//    generarCuchillos(nivel, sdlRenderer, mapa, posicionDeEscenario);
//    generarTubos(nivel, sdlRenderer, mapa, posicionDeEscenario);
//    generarEnemigo(nivel, sdlRenderer, mapa, posicionDeEscenario);
//    generarTransicion(nivel, sdlRenderer, mapa, posicionDeJugador);
}

Entidad *NivelServidor::generarEscenario(const string &nivel, Mapa *mapa) {
    Locator::logger()->log(DEBUG, "Se genera escenario para " + nivel);

    Configuracion *config = Locator::configuracion();
    int profundidad = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");
    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");

    Locator::logger()->log(DEBUG, "Se cargo profundidad para escenario: " + to_string(profundidad));
    Locator::logger()->log(DEBUG, "Se cargo ancho para escenario: " + to_string(anchoNivel));

    Entidad *escenario = mapa->crearEntidad();
    auto *posicion = new Posicion(0, profundidad, 0);
    auto *tipo = new Tipo(ESCENARIO);
    auto *nivelEstado = new Nivel(nivel);
    auto *fisica = new FisicaDeEscenario(anchoNivel);


    escenario->agregarComportamiento("fisica", fisica);
    escenario->agregarEstado("posicion", posicion);
    escenario->agregarEstado("mapa", mapa);
    escenario->agregarEstado("tipo", tipo);
    escenario->agregarEstado("nivel", nivelEstado);

    return escenario;

}
