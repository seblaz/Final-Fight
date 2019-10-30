//
// Created by sebas on 8/10/19.
//

#include "NivelCliente.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
//#include "../graficos/GraficoDePantallaCompleta.h"
#include "../modelo/serializables/Posicion.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeCody.h"
#include "../graficos/Grafico.h"
#include "../modelo/serializables/Nivel.h"
#include "../graficos/GraficoDeEscenario.h"
#include "Animador.h"
#include "../modelo/Personaje.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeHaggar.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeMaki.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeGuy.h"
#include "../graficos/GraficoDeTransicion.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDePoison.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeCaja.h"
#include "../modelo/serializables/TipoElemento.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeCuchillo.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeNeumatico.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeTubo.h"
#include "../modelo/serializables/NumeroJugador.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeIndicador.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeGuy.h"
#include "../graficos/GraficoJugador.h"
#include "../graficos/GraficoMenuSeleccion.h"

void NivelCliente::generarPantallaDeEspera(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se genera la pantalla de espera.");

    Entidad *pantalla = mapa->crearEntidad();

    auto *sprite = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallaDeEspera/sprite/src");
    auto *posicion = new Posicion(0, 0, 0);

    pantalla->agregarEstado("posicion", posicion);
    pantalla->agregarEstado("sprite", sprite);
    pantalla->agregarEstado("mapa", mapa);
}

void NivelCliente::generarMenuSeleccion(Mapa *mapa, Entidad *pantalla) {
    Locator::logger()->log(INFO, "Se genera el menu de seleccion.");

    auto *sprite = Locator::fabricaDeSprites()->getSpriteConfigPath("/pantallaDeSeleccion/fondo/src");
    auto *grafico = new GraficoMenuSeleccion();
    auto *personaje = new Personaje(GUY);
    auto *spriteSelector = Locator::fabricaDeSprites()->getSpriteBySrc("assets/varios/selectorMenu.png");

    pantalla->agregarEstado("sprite", sprite);
    pantalla->agregarEstado("mapa", mapa);
    pantalla->agregarEstado("personaje marcado", personaje);
    pantalla->agregarEstado("sprite selector", spriteSelector);
    pantalla->agregarComportamiento("grafico", grafico);
}

void NivelCliente::generarJugador(Mapa *mapa, IdEntidad idEntidad, Entidad *jugador) {
    Locator::logger()->log(INFO, "Se genera jugador.");
    Configuracion *config = Locator::configuracion();

    auto *personaje = jugador->getEstado<Personaje>("personaje");
    auto *numeroJugador = jugador->getEstado<NumeroJugador>("numeroJugador");
    Locator::logger()->log(INFO, "Se obtuvo personaje." + Personaje::PersonajeACadena(personaje->getPersonaje()));
    Locator::logger()->log(INFO, "Se obtuvo jugador numero" + to_string(numeroJugador->numeroJugador));

    auto *spriteIndicador = Locator::fabricaDeSprites()->getSpriteConfigPath("/personajes/indicadores/jugador" + to_string(numeroJugador->numeroJugador) + "/src");
    auto *animacionIndicador = FabricaDeAnimacionesDeIndicador::indicador();

    jugador->agregarEstado("spriteIndicador", spriteIndicador);
    jugador->agregarEstado("animacionIndicador", animacionIndicador);

    string srcSpritePersonaje;
    FabricaDeAnimacionesDePersonaje *fabricaDeAnimaciones;

    switch (personaje->getPersonaje()) {
        case HAGGAR:
            srcSpritePersonaje = config->getValue("/personajes/haggar/src");
            fabricaDeAnimaciones = new FabricaDeAnimacionesDeHaggar();
            break;
        case CODY:
            srcSpritePersonaje = config->getValue("/personajes/cody/src");
            fabricaDeAnimaciones = new FabricaDeAnimacionesDeCody();
            break;
        case MAKI:
            srcSpritePersonaje = config->getValue("/personajes/maki/src");
            fabricaDeAnimaciones = new FabricaDeAnimacionesDeMaki();
            break;
        case GUY:
            srcSpritePersonaje = config->getValue("/personajes/guy/src");
            fabricaDeAnimaciones = new FabricaDeAnimacionesDeGuy();
            break;
        default:
            Locator::logger()->log(ERROR, "Se trató de crear un jugador con un personaje incorrecto: " +
                                          Personaje::PersonajeACadena(personaje->getPersonaje()) + ".");
            return;
    }

    auto *animacion = fabricaDeAnimaciones->reposando();
    auto *spriteJugador = Locator::fabricaDeSprites()->getSpriteBySrc(srcSpritePersonaje);
    auto *grafico = new GraficoJugador();
    auto *animador = new Animador();

    jugador->agregarEstado("sprite", spriteJugador);
    jugador->agregarEstado("animacion", animacion);
    jugador->agregarEstado("fabrica de animaciones", fabricaDeAnimaciones);
    jugador->agregarComportamiento("grafico", grafico);
    jugador->agregarComportamiento("animador", animador);
}

void NivelCliente::generarEscenario(Mapa *mapa, Entidad *escenario) {
    Configuracion *config = Locator::configuracion();

    auto *nivelEstado = escenario->getEstado<Nivel>("nivel");
    string nivel = nivelEstado->nivel();
    Locator::logger()->log(DEBUG, "Se genera escenario para " + nivel);

    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    int cantidadDeCapas = config->getIntValue("/niveles/" + nivel + "/escenario/sprite/capas/cantidad");

    Locator::logger()->log(DEBUG, "Se cargo ancho para escenario: " + to_string(anchoNivel));
    Locator::logger()->log(DEBUG, "Se cargo cantidad de capas para escenario: " + to_string(cantidadDeCapas));

    auto *sprite = Locator::fabricaDeSprites()->getSpriteConfigPath("/niveles/" + nivel + "/escenario/sprite/src");

    vector<SDL_Texture *> sprites(cantidadDeCapas);
    vector<SDL_Rect> posicionesSprite(cantidadDeCapas);
    vector<float> distanciasAlFondo(cantidadDeCapas);

    for (int i = 0; i < cantidadDeCapas; i++) {
        int x = config->getIntValue("/niveles/" + nivel + "/escenario/sprite/capas/capa" + to_string(i) + "/x");
        int y = config->getIntValue("/niveles/" + nivel + "/escenario/sprite/capas/capa" + to_string(i) + "/y");
        int alto = config->getIntValue("/niveles/" + nivel + "/escenario/sprite/capas/capa" + to_string(i) + "/alto");
        float distanciaAlFondo = config->getFloatValue(
                "/niveles/" + nivel + "/escenario/sprite/capas/capa" + to_string(i) + "/distanciaAlFondo");

        Locator::logger()->log(DEBUG, "Se obtiene eje x para capa " + to_string(i + 1) + ": " + to_string(x));
        Locator::logger()->log(DEBUG, "Se obtiene eje y para capa " + to_string(i + 1) + ": " + to_string(y));
        Locator::logger()->log(DEBUG, "Se obtiene alto para capa " + to_string(i + 1) + ": " + to_string(alto));
        Locator::logger()->log(DEBUG, "Se obtiene distancia al fondo para capa " + to_string(i + 1) + ": " +
                                      to_string(distanciaAlFondo));

        sprites[i] = sprite->getTexture();
        posicionesSprite[i] = {x, y, 0, alto};
        distanciasAlFondo[i] = distanciaAlFondo;
    }

    float escalaHorizontal = (float) anchoNivel / (float) sprite->ancho();
    auto *grafico = new GraficoDeEscenario(sprites, posicionesSprite, distanciasAlFondo, escalaHorizontal);

    escenario->agregarEstado("sprite", sprite);
    escenario->agregarEstado("mapa", mapa);
    escenario->agregarComportamiento("grafico", grafico);
}

void NivelCliente::generarTransicion(Mapa *mapa, Entidad *transicion) {
    Locator::logger()->log(DEBUG, "Se genera transicion");

    auto *grafico = new GraficoDeTransicion();

    transicion->agregarComportamiento("grafico", grafico);
}

void NivelCliente::generarEnemigo(Mapa *mapa, Entidad *enemigo) {
    Locator::logger()->log(INFO, "Se genera enemigo");
    string spritePath = "assets/personajes/poison.png";

    auto *spriteEnemigo = Locator::fabricaDeSprites()->getSpriteBySrc("assets/personajes/poison.png");
    auto *fabricaDeEnemigo = new FabricaDeAnimacionesDePoison();
    auto *graficoDeEnemigo = new Grafico();
    auto *animacion = fabricaDeEnemigo->caminando();
    enemigo->agregarEstado("sprite", spriteEnemigo);
    enemigo->agregarEstado("fabrica de animaciones", fabricaDeEnemigo);
    enemigo->agregarEstado("animacion", animacion);
    enemigo->agregarComportamiento("grafico", graficoDeEnemigo);

}

void NivelCliente::generarElementos(Mapa *mapa, Entidad *elemento) {
    Configuracion *config = Locator::configuracion();
    auto *tipoElemento = elemento->getEstado<TipoElemento>("tipo elemento");
    string srcSprite;
    AnimacionCliente *animacion;
    int ART = tipoElemento->getElemento();
    switch (ART) {
        case CAJA:
            srcSprite = config->getValue("/niveles/nivel1/escenario/objetos/caja/sprite/src");
            animacion = FabricaDeAnimacionesDeCaja::standby();
            break;
        case CUCHILLO:
            srcSprite = config->getValue("/niveles/nivel1/escenario/objetos/cuchillo/sprite/src");
            animacion = FabricaDeAnimacionesDeCuchillo::standby();
            break;
        case NEUMATICO:
            srcSprite = config->getValue("/niveles/nivel1/escenario/objetos/neumatico/sprite/src");
            animacion = FabricaDeAnimacionesDeNeumatico::standby();
            break;
        case TUBO:
            srcSprite = config->getValue("/niveles/nivel1/escenario/objetos/tubo/sprite/src");
            animacion = FabricaDeAnimacionesDeTubo::standby();
            break;
        default:
            Locator::logger()->log(ERROR, "Se trata de crear un elemento inexistente.");
            return;
    }

    auto *sprite = Locator::fabricaDeSprites()->getSpriteBySrc(srcSprite);
    auto *grafico = new Grafico();

    elemento->agregarEstado("sprite", sprite);
    elemento->agregarEstado("animacion", animacion);
    elemento->agregarComportamiento("grafico", grafico);

}
