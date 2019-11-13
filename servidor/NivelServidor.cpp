//
// Created by sebas on 6/10/19.
//

#include <random>
#include "NivelServidor.h"
#include "../modelo/serializables/Nivel.h"
#include "../estados/Reposando.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../modelo/serializables/Opacidad.h"
#include "../fisica/FisicaDeTransicion.h"
#include "../modelo/serializables/TipoElemento.h"
#include "../modelo/serializables/Actividad.h"
#include "../modelo/serializables/NumeroJugador.h"
#include "FabricaDeAnimacionesServidor.h"
#include "../modelo/serializables/IndiceSprite.h"
#include "../modelo/serializables/Energia.h"
#include "../modelo/envolventes/EnvolventeVolumen.h"
#include "../estados/ia/BuscarJugadores.h"
#include "../modelo/serializables/Puntaje.h"
#include "../modelo/envolventes/EnvolventeAtaque.h"
#include "../modelo/serializables/Arma.h"
#include "../modelo/GolpesSoportables.h"

void NivelServidor::generarMenuSeleccion(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se genera el menu de seleccion.");

    Entidad *pantalla = mapa->crearPantalla();
    auto *posicion = new Posicion(0, 10, 0);
    auto *tipo = new Tipo(PANTALLA_SELECCION);
    pantalla->agregarEstado("posicion", posicion);
    pantalla->agregarEstado("tipo", tipo);
}


Entidad *NivelServidor::generarJugador(Mapa *mapa, enum PERSONAJE personajeSeleccionado, int contadorJugador) {
    Locator::logger()->log(INFO, "Se genera jugador.");

    auto *jugador = mapa->crearJugador();
    auto *estado = new Reposando(jugador);
    auto *velocidad = new Velocidad();
    auto *orientacion = new Orientacion;
    auto *tipo = new Tipo(JUGADOR);
    auto *indiceSprite = new IndiceSprite;
    auto *fisica = new FisicaDePersonaje(jugador);
    auto *actividad = new Actividad(true);
    auto *posicion = new Posicion(200, 100, 0);
    auto *numeroJugador = new NumeroJugador(contadorJugador);
    auto *estadoDePersonaje = new EstadoDePersonaje(REPOSANDO);
    auto *animacionServidor = FabricaDeAnimacionesServidor::getAnimacion(jugador, personajeSeleccionado, "reposando");
    auto *energia = new Energia(100,3);
    auto *envolvente = new EnvolventeVolumen(posicion, 120, 50, 15);
    auto *envolventeDeAtaque = new EnvolventeAtaque(posicion, 120, 100, 30, orientacion);
    auto* puntaje = new Puntaje();
    auto* arma = new Arma();

    jugador->agregarEstado("tipo", tipo);
    jugador->agregarEstado("posicion", posicion);
    jugador->agregarEstado("velocidad", velocidad);
    jugador->agregarEstado("actividad", actividad);
    jugador->agregarEstado("orientacion", orientacion);
    jugador->agregarEstado("indice sprite", indiceSprite);
    jugador->agregarEstado("numeroJugador", numeroJugador);
    jugador->agregarEstado("estado de personaje", estadoDePersonaje);
    jugador->agregarEstado("personaje", new Personaje(personajeSeleccionado));
    jugador->agregarEstado("energia", energia);
    jugador->agregarEstado("envolvente", envolvente);
    jugador->agregarEstado("puntaje", puntaje);
    jugador->agregarEstado("envolvente ataque", envolventeDeAtaque);
    jugador->agregarEstado("arma", arma);
    jugador->agregarComportamiento("estado", estado);
    jugador->agregarComportamiento("fisica", fisica);
    jugador->agregarComportamiento("animacion servidor", animacionServidor);

    return jugador;
}

void NivelServidor::generarNivel(const string &nivel, Mapa *mapa) {
    Locator::logger()->log(DEBUG, "Se genera " + nivel);

    Entidad *escenario = generarEscenario(nivel, mapa);

    /**
     * Dependencias.
     */
    Jugadores *jugadores = mapa->getJugadores();
    jugadores->reiniciarPosiciones(200, 100);

    auto *posicionDeEscenario = escenario->getEstado<Posicion>("posicion");

    generarElementos(nivel, mapa, posicionDeEscenario, CAJA);
    generarElementos(nivel, mapa, posicionDeEscenario, NEUMATICO);
    generarArmas(nivel, mapa, posicionDeEscenario, CUCHILLO);
    generarArmas(nivel, mapa, posicionDeEscenario, TUBO);
    generarEnemigo(nivel, mapa, posicionDeEscenario, jugadores);
    generarTransicion(nivel, mapa, jugadores);
}

Entidad *NivelServidor::generarEscenario(const string &nivel, Mapa *mapa) {
    Locator::logger()->log(DEBUG, "Se genera escenario para " + nivel);

    Configuracion *config = Locator::configuracion();
    Colisionables *colisionables = Locator::colisionables();
    int profundidad = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");
    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    colisionables->addLimitesDeEscenario(profundidad, 0);

    Locator::logger()->log(DEBUG, "Se cargo profundidad para escenario: " + to_string(profundidad));
    Locator::logger()->log(DEBUG, "Se cargo ancho para escenario: " + to_string(anchoNivel));

    Entidad *escenario = mapa->crearEscenario();
    auto *posicion = new Posicion(0, profundidad, 0);
    auto *tipo = new Tipo(ESCENARIO);
    auto *nivelEstado = new Nivel(nivel);
    auto *fisica = new FisicaDeEscenario(escenario, anchoNivel);


    escenario->agregarComportamiento("fisica", fisica);
    escenario->agregarEstado("posicion", posicion);
    escenario->agregarEstado("tipo", tipo);
    escenario->agregarEstado("nivel", nivelEstado);

    return escenario;

}

void NivelServidor::generarTransicion(const string &nivel, Mapa *mapa, Jugadores *posicionDeJugadores) {

    Entidad *transicion = mapa->crearTransicion();
    auto *tipo = new Tipo(TRANSICION);
    int anchoDeNivel = Locator::configuracion()->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    auto *posicion = new Posicion(0, 1, 0);
    auto *opacidad = new Opacidad();
    auto *fisicaDeTransicion = new FisicaDeTransicion(transicion, anchoDeNivel);

    transicion->agregarEstado("posicion", posicion);
    transicion->agregarEstado("tipo", tipo);
    transicion->agregarEstado("opacidad", opacidad);
    transicion->agregarEstado("posicion de jugadoresMax", posicionDeJugadores);
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

void NivelServidor::generarEnemigo(const string &nivel, Mapa *mapa, Posicion *posicionDeEscenario, Jugadores* jugadores) {

    Configuracion *config = Locator::configuracion();
    int cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/enemigos/cantidad");
    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    int profundidadNivel = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");
    string spritePath = config->getValue("/niveles/" + nivel + "/escenario/enemigos/sprite/src");
    auto *personaje = new Personaje(POISSON);


    for (int i = 0; i < cantidad; i++) {
        Locator::logger()->log(INFO, "Se genera enemigo");

        Entidad *enemigo = mapa->crearEnemigo();

        auto *tipo = new Tipo(ENEMIGO);
        auto *comportamiento = new BuscarJugadores(enemigo, jugadores);
        auto *velocidadDeEnemigo = new Velocidad();
        auto *orientacionDeEnemigo = new Orientacion;
        auto *fisicaDeEnemigo = new FisicaDePersonaje(enemigo);
        auto *estado = new Reposando(enemigo);
        auto *estadoDePersonaje = new EstadoDePersonaje(REPOSANDO);
        auto *posicionEnemigoRandom = new Posicion(generarPosicionX(anchoNivel), generarPosicionY(profundidadNivel), 0);
        auto *indiceSprite = new IndiceSprite;
        auto *animacionServidor = FabricaDeAnimacionesServidor::getAnimacion(enemigo, POISSON, "reposando");
        auto *energia = new Energia(100,1);
        auto *envolvente = new EnvolventeVolumen(posicionEnemigoRandom, 120, 50, 30);

        enemigo->agregarEstado("tipo", tipo);
        enemigo->agregarEstado("personaje", personaje);
        enemigo->agregarEstado("indice sprite", indiceSprite);
        enemigo->agregarEstado("velocidad", velocidadDeEnemigo);
        enemigo->agregarEstado("posicion", posicionEnemigoRandom);
        enemigo->agregarEstado("orientacion", orientacionDeEnemigo);
        enemigo->agregarEstado("estado de personaje", estadoDePersonaje);
        enemigo->agregarEstado("posicion de escenario", posicionDeEscenario);
        enemigo->agregarEstado("energia", energia);
        enemigo->agregarEstado("envolvente", envolvente);
        enemigo->agregarComportamiento("estado", estado);
        enemigo->agregarComportamiento("fisica", fisicaDeEnemigo);
        enemigo->agregarComportamiento("comportamiento", comportamiento);
        enemigo->agregarComportamiento("animacion servidor", animacionServidor);
    }
}

void NivelServidor::generarElementos(const string &nivel, Mapa *mapa, Posicion *posicionDeEscenario, elementos ART) {
    Configuracion *config = Locator::configuracion();
    int golpesMaximos;

    int cantidad;
    switch (ART) {
        case CAJA:
            cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/objetos/caja/cantidad");
            golpesMaximos = 2;
            break;
        case NEUMATICO:
            cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/objetos/neumatico/cantidad");
            golpesMaximos = 1;
            break;
        default:
            cantidad = 0;
            golpesMaximos = 0;
    }
    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    int profundidadNivel = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");

    auto *tipo = new Tipo(ELEMENTO);
    auto *tipoElemento = new TipoElemento(ART);

    for (int i = 1; i <= cantidad; i++) {
        Locator::logger()->log(INFO, "Se inicia la construccion del elemento random :" + to_string(i));
        auto *indiceSprite = new IndiceSprite;
        auto elementoRandom = mapa->crearElemento();

        auto *posicionElementoRandom = new Posicion(generarPosicionX(anchoNivel), generarPosicionY(profundidadNivel),
                                                    0);
        auto *envolvente = new EnvolventeVolumen(posicionElementoRandom, 120, 75, 8);
        auto *velocidad = new Velocidad();
        auto* golpesSoportables = new GolpesSoportables(golpesMaximos);
        
        elementoRandom->agregarEstado("posicion", posicionElementoRandom);
        elementoRandom->agregarEstado("tipo", tipo);
        elementoRandom->agregarEstado("indice sprite", indiceSprite);
        elementoRandom->agregarEstado("tipo elemento", tipoElemento);
        elementoRandom->agregarEstado("envolvente", envolvente);
        elementoRandom->agregarEstado("velocidad", velocidad);
        elementoRandom->agregarEstado("golpes soportables", golpesSoportables);
        elementoRandom->agregarEstado("posicion de escenario", posicionDeEscenario);
    }

}

void NivelServidor::generarArmas(const string &nivel, Mapa *mapa, Posicion *posicionDeEscenario, elementos ART) {
    Configuracion *config = Locator::configuracion();
    int cantidad;
    switch (ART) {
        case CUCHILLO:
            cantidad = config->getIntValue("/niveles/" + nivel + "/escenario/objetos/cuchillo/cantidad");
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
    auto *tipoElemento = new TipoElemento(ART);

    for (int i = 1; i <= cantidad; i++) {
        Locator::logger()->log(INFO, "Se inicia la construccion del elemento random :" + to_string(i));
        auto *indiceSprite = new IndiceSprite;
        auto armaRandom = mapa->crearArma();

        auto *posicionElementoRandom = new Posicion(generarPosicionX(anchoNivel), generarPosicionY(profundidadNivel),
                                                    0);
        auto *envolvente = new EnvolventeVolumen(posicionElementoRandom, 120, 20, 8);

        armaRandom->agregarEstado("posicion", posicionElementoRandom);
        armaRandom->agregarEstado("tipo", tipo);
        armaRandom->agregarEstado("indice sprite", indiceSprite);
        armaRandom->agregarEstado("tipo elemento", tipoElemento);
        armaRandom->agregarEstado("envolvente", envolvente);
        armaRandom->agregarEstado("posicion de escenario", posicionDeEscenario);
    }
}
