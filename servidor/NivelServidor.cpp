//
// Created by sebas on 6/10/19.
//

#include <random>
#include "NivelServidor.h"
#include "../modelo/Nivel.h"
#include "../estados/Reposando.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../graficos/GraficoDeTransicion.h"
#include "../modelo/Opacidad.h"
#include "../fisica/FisicaDeTransicion.h"
#include "../graficos/Sprite.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDePoison.h"
#include "../estados/ia/Patrullar.h"
#include "../estados/Caminando.h"
#include "../modelo/TipoElemento.h"
#include "../modelo/Actividad.h"

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



Entidad * NivelServidor::generarJugador(Mapa *mapa, enum PERSONAJE personajeSeleccionado) {
    Locator::logger()->log(INFO, "Se genera jugador.");

    auto* jugador = mapa->crearJugador();
    auto* posicion = new Posicion(200, 100, 0);
    auto *velocidad = new Velocidad();
    auto *orientacion = new Orientacion;
    auto *tipo = new Tipo(JUGADOR);
    EstadoDePersonaje *estado = new Reposando();
    auto *fisica = new FisicaDePersonaje();
    auto *actividad = new Actividad(true);

    jugador->agregarEstado("tipo", tipo);
    jugador->agregarEstado("posicion", posicion);
    jugador->agregarEstado("velocidad", velocidad);
    jugador->agregarEstado("orientacion", orientacion);
    jugador->agregarEstado("estado", estado);
    jugador->agregarEstado("personaje", new Personaje(personajeSeleccionado));
    jugador->agregarEstado("actividad", actividad);
    jugador->agregarComportamiento("estado", estado);
    jugador->agregarComportamiento("fisica", fisica);
    return jugador;
}

void NivelServidor::generarNivel(const string &nivel, Mapa *mapa) {
    mapa->vaciarMapa();
    Locator::logger()->log(DEBUG, "Se genera " + nivel);

    Entidad *escenario = generarEscenario(nivel, mapa);

    /**
     * Dependencias.
     */
    Jugadores* jugadores = mapa->getJugadores();
    jugadores->reiniciarPosiciones(200, 100);

    Entidad *jugador = mapa->getJugador();
    auto *posicionDeJugador = jugador->getEstado<Posicion>("posicion");
    auto *posicionDeEscenario = escenario->getEstado<Posicion>("posicion");
    escenario->agregarEstado("posicion de jugador", posicionDeJugador);
    jugador->agregarEstado("posicion de escenario", posicionDeEscenario);
    //posicionDeJugador->x = 200;
    //posicionDeJugador->y = 100;

//    generarCajas(nivel, sdlRenderer, mapa, posicionDeEscenario);
//    generarNeumaticos(nivel, sdlRenderer, mapa, posicionDeEscenario);
//    generarCuchillos(nivel, sdlRenderer, mapa, posicionDeEscenario);
//    generarTubos(nivel, sdlRenderer, mapa, posicionDeEscenario);
    generarElementos(nivel, mapa, posicionDeEscenario, CAJA);
    generarElementos(nivel, mapa, posicionDeEscenario, CUCHILLO);
    generarElementos(nivel, mapa, posicionDeEscenario, TUBO);
    generarElementos(nivel, mapa, posicionDeEscenario, NEUMATICO);
    generarEnemigo(nivel, mapa, posicionDeEscenario);
    generarTransicion(nivel, mapa, posicionDeJugador);
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

void NivelServidor::generarTransicion(const string &nivel, Mapa *mapa, Posicion* posicionDeJugador) {
    //Locator::logger()->log(DEBUG, "Se genera transicion");

    Entidad *transicion = mapa->crearEntidad();
    auto *tipo = new Tipo(TRANSICION);
    int anchoDeNivel = Locator::configuracion()->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    auto *posicion = new Posicion(0, 1, 0);
    auto *opacidad = new Opacidad();
    auto* fisicaDeTransicion = new FisicaDeTransicion(anchoDeNivel);

    transicion->agregarEstado("posicion", posicion);
    transicion->agregarEstado("tipo", tipo);
    transicion->agregarEstado("opacidad", opacidad);
    transicion->agregarEstado("posicion de jugador", posicionDeJugador);
    transicion->agregarComportamiento("fisica de transicion", fisicaDeTransicion);
}

int generarPosicionX(int frontera) {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(400, frontera - 400);
    return dist(mt);
}

int generarPosicionY(int frontera) {
    random_device rd;
    mt19937 mt(rd());
    uniform_real_distribution<double> dist(20, frontera - 20);
    return dist(mt);
}

void NivelServidor::generarEnemigo(const string &nivel, Mapa *mapa, Posicion *posicionDeEscenario) {

    Configuracion *config = Locator::configuracion();
    int cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/enemigos/cantidad");
    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    int profundidadNivel = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");
    string spritePath = config->getValue("/niveles/" + nivel + "/escenario/enemigos/sprite/src");

    for (int i = 0; i < cantidad; i++) {
        Locator::logger()->log(INFO, "Se genera enemigo");

        Entidad *enemigo = mapa->crearEntidad();

        auto* tipo = new Tipo(ENEMIGO);
        auto *velocidadDeEnemigo = new Velocidad();
        auto *posicionEnemigoRandom = new Posicion(generarPosicionX(anchoNivel), generarPosicionY(profundidadNivel), 0);
        auto *orientacionDeEnemigo = new Orientacion;
        auto *comportamiento = new Patrullar();
        auto *fisicaDeEnemigo = new FisicaDePersonaje();
        EstadoDePersonaje *estado = new Caminando();

        enemigo->agregarEstado("tipo", tipo);
        enemigo->agregarEstado("estado", estado);
        enemigo->agregarEstado("posicion", posicionEnemigoRandom);
        enemigo->agregarEstado("velocidad", velocidadDeEnemigo);
        enemigo->agregarEstado("posicion de escenario", posicionDeEscenario);
        enemigo->agregarEstado("orientacion", orientacionDeEnemigo);
        enemigo->agregarComportamiento("comportamiento", comportamiento);
        enemigo->agregarComportamiento("fisica", fisicaDeEnemigo);
    }
}

void NivelServidor::generarElementos(const string &nivel, Mapa *mapa, Posicion *posicionDeEscenario, elementos ART) {
    Configuracion *config = Locator::configuracion();
    int cantidad;
    switch (ART) {
        case CAJA:
            cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/objetos/caja/cantidad");
            break;
        case CUCHILLO:
            cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/objetos/cuchillo/cantidad");
            break;
        case NEUMATICO:
            cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/objetos/neumatico/cantidad");
            break;
        case TUBO:
            cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/objetos/tubo/cantidad");
            break;
        default:
            cantidad = 0;
    }
            int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
            int profundidadNivel = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");

            auto *tipo = new Tipo(ELEMENTO);
            auto *nivelElemento = new Nivel(nivel);
            auto *tipoElemento = new TipoElemento(ART);

            for (int i = 1; i <= cantidad; i++) {
                Locator::logger()->log(INFO, "Se inicia la construccion del elemento random :" + to_string(i));
                auto elementoRandom = mapa->crearEntidad();

                auto *posicionElementoRandom = new Posicion(generarPosicionX(anchoNivel), generarPosicionY(profundidadNivel),
                                                        0);
                elementoRandom->agregarEstado("posicion", posicionElementoRandom);
                elementoRandom->agregarEstado("tipo", tipo);
                elementoRandom->agregarEstado("nivel", nivelElemento);
                elementoRandom->agregarEstado("tipo elemento" , tipoElemento);
                elementoRandom->agregarEstado("posicion de escenario", posicionDeEscenario);
            }

}
