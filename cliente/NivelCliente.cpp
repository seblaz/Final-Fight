//
// Created by sebas on 8/10/19.
//

#include "NivelCliente.h"
#include "../servicios/Locator.h"
#include "../graficos/Grafico.h"
#include "../modelo/serializables/Nivel.h"
#include "../graficos/GraficoDeEscenario.h"
#include "Animador.h"
#include "AnimadorElemento.h"
#include "../graficos/GraficoDeTransicion.h"
#include "../graficos/GraficoArma.h"
#include "../modelo/serializables/Elemento.h"
#include "../modelo/serializables/NumeroJugador.h"
#include "../graficos/GraficoJugador.h"
#include "../graficos/FabricaDeAnimacionesCliente.h"
#include "ReproductorSonidoPersonaje.h"
#include "../modelo/serializables/Arma.h"


void NivelCliente::generarJugador(Mapa *mapa, IdEntidad idEntidad, Entidad *jugador) {
    Locator::logger()->log(INFO, "Se genera jugador.");
    Configuracion *config = Locator::configuracion();

    auto *personaje = jugador->getEstado<Personaje>("personaje");
    auto *numeroJugador = jugador->getEstado<NumeroJugador>("numeroJugador");
    Locator::logger()->log(INFO, "Se obtuvo personaje." + Personaje::PersonajeACadena(personaje->getPersonaje()));
    Locator::logger()->log(INFO, "Se obtuvo jugador numero" + to_string(numeroJugador->numeroJugador));

    auto *spriteIndicador = Locator::fabricaDeSprites()->getSpriteConfigPath(
            "/personajes/indicadores/jugador" + to_string(numeroJugador->numeroJugador) + "/src");
    auto *animacionIndicador = FabricaDeAnimacionesCliente("/animaciones").getAnimacion("/indicador");

    jugador->agregarEstado("spriteIndicador", spriteIndicador);
    jugador->agregarEstado("animacionIndicador", animacionIndicador);

    string srcSpritePersonaje;
    FabricaDeAnimacionesCliente *fabricaDeAnimaciones;

    ReproductorSonidoPersonaje *reproductorSonidoPersonaje;

    switch (personaje->getPersonaje()) {
        case HAGGAR:
            srcSpritePersonaje = config->getValue("/personajes/haggar/src");
            fabricaDeAnimaciones = new FabricaDeAnimacionesCliente("/animaciones/haggar");
  //          reproductorSonidoPersonaje = new ReproductorSonidoPersonaje("/sonidos/personaje/cody/");
            break;
        case CODY:
            srcSpritePersonaje = config->getValue("/personajes/cody/src");
            fabricaDeAnimaciones = new FabricaDeAnimacionesCliente("/animaciones/cody");
    //        reproductorSonidoPersonaje = new ReproductorSonidoPersonaje("/sonidos/personaje/cody/");
            break;
        case MAKI:
            srcSpritePersonaje = config->getValue("/personajes/maki/src");
            fabricaDeAnimaciones = new FabricaDeAnimacionesCliente("/animaciones/maki");
      //      reproductorSonidoPersonaje = new ReproductorSonidoPersonaje("/sonidos/personaje/cody/");
            break;
        case GUY:
            srcSpritePersonaje = config->getValue("/personajes/guy/src");
            fabricaDeAnimaciones = new FabricaDeAnimacionesCliente("/animaciones/guy");
    //        reproductorSonidoPersonaje = new ReproductorSonidoPersonaje("/sonidos/personaje/cody/");
            break;
        default:
            Locator::logger()->log(ERROR, "Se trató de crear un jugador con un personaje incorrecto: " +
                                          Personaje::PersonajeACadena(personaje->getPersonaje()) + ".");
            return;
    }

    auto *animacion = fabricaDeAnimaciones->getAnimacion("/reposando");
    auto *spriteJugador = Locator::fabricaDeSprites()->getSpriteBySrc(srcSpritePersonaje);
    auto *grafico = new GraficoJugador(jugador);
    auto *animador = new Animador(jugador);

    jugador->agregarEstado("sprite", spriteJugador);
    jugador->agregarEstado("animacion", animacion);
    jugador->agregarEstado("fabrica de animaciones", fabricaDeAnimaciones);
    jugador->agregarComportamiento("grafico", grafico);
    jugador->agregarComportamiento("animador", animador);
   // jugador->agregarComportamiento("reproductor", reproductorSonidoPersonaje);
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
    auto *grafico = new GraficoDeEscenario(escenario, sprites, posicionesSprite, distanciasAlFondo, escalaHorizontal);

    escenario->agregarEstado("sprite", sprite);
    escenario->agregarComportamiento("grafico", grafico);

}

void NivelCliente::generarTransicion(Mapa *mapa, Entidad *transicion) {
    Locator::logger()->log(DEBUG, "Se genera transicion");

    auto *grafico = new GraficoDeTransicion(transicion);

    transicion->agregarComportamiento("grafico", grafico);
}

void NivelCliente::generarEnemigo(Mapa *mapa, Entidad *enemigo) {
    Locator::logger()->log(INFO, "Se genera enemigo");
    string spritePath = "assets/personajes/poison.png";

    auto *spriteEnemigo = Locator::fabricaDeSprites()->getSpriteBySrc("assets/personajes/poison.png");
    auto *fabricaDeEnemigo = new FabricaDeAnimacionesCliente("/animaciones/poisson");
    auto *graficoDeEnemigo = new Grafico(enemigo);
    auto *animacion = fabricaDeEnemigo->getAnimacion(REPOSANDO);
    auto *animador = new Animador(enemigo);
    enemigo->agregarEstado("sprite", spriteEnemigo);
    enemigo->agregarEstado("fabrica de animaciones", fabricaDeEnemigo);
    enemigo->agregarEstado("animacion", animacion);
    enemigo->agregarComportamiento("grafico", graficoDeEnemigo);
    enemigo->agregarComportamiento("animador", animador);

//    auto *reproductorSonidoPersonaje = new ReproductorSonidoPersonaje("/sonidos/enemigo/poison/");
//    enemigo->agregarComportamiento("reproductor", reproductorSonidoPersonaje);

}

void NivelCliente::generarElemento(Mapa *mapa, Entidad *entidad) {
    Configuracion *config = Locator::configuracion();
    string tipoElemento =  Elemento::ElementoACadena(entidad->getEstado<Elemento>("elemento")->getElemento());

    auto *fabrica = new FabricaDeAnimacionesCliente("/animaciones/objetos/" + tipoElemento);
    AnimacionCliente *animacion = fabrica->getAnimacion("/sano");

    string srcSprite = config->getValue("/niveles/nivel1/escenario/objetos/" + tipoElemento + "/sprite/src");
    auto *sprite = Locator::fabricaDeSprites()->getSpriteBySrc(srcSprite);
    auto *grafico = new Grafico(entidad);
    auto *animador = new AnimadorElemento(entidad);

    entidad->agregarEstado("sprite", sprite);
    entidad->agregarEstado("fabrica de animaciones", fabrica);
    entidad->agregarEstado("animacion", animacion);
    entidad->agregarComportamiento("grafico", grafico);
    entidad->agregarComportamiento("animador", animador);

}

void NivelCliente::generarArma(Mapa *mapa, Entidad *arma) {
    Configuracion *config = Locator::configuracion();
    string tipoArma = Arma::armaACadena(arma->getEstado<Arma>("arma")->getArma());

    string srcSprite = config->getValue("/niveles/nivel1/escenario/objetos/" + tipoArma + "/sprite/src");
    AnimacionCliente *animacion = FabricaDeAnimacionesCliente("/animaciones/objetos").getAnimacion("/" + tipoArma);

    auto *sprite = Locator::fabricaDeSprites()->getSpriteBySrc(srcSprite);
    auto *grafico = new GraficoArma(arma);

    arma->agregarEstado("sprite", sprite);
    arma->agregarEstado("animacion", animacion);
    arma->agregarComportamiento("grafico", grafico);
}
