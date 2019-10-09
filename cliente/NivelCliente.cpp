//
// Created by sebas on 8/10/19.
//

#include "NivelCliente.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../graficos/GraficoDePantallaCompleta.h"
#include "../modelo/Posicion.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeCody.h"
#include "../graficos/Grafico.h"
#include "../modelo/Nivel.h"
#include "../graficos/GraficoDeEscenario.h"

void NivelCliente::generarPantallaDeEspera(Mapa *mapa) {
    Locator::logger()->log(INFO, "Se genera la pantalla de espera.");
    Configuracion *config = Locator::configuracion();
    string srcSprite = config->getValue("/pantallaDeEspera/sprite/src");
    SDL_Renderer *sdlRenderer = Locator::renderer();

    Entidad *pantalla = mapa->crearEntidad();

    auto *sprite = new Sprite(sdlRenderer, srcSprite);
    auto *posicion = new Posicion(0, 0, 0);
    auto *grafico = new GraficoDePantallaCompleta();
//    auto *entrada = new EntradaPantallaDeEspera();

//    pantalla->agregarComportamiento("entrada", entrada);
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
//    auto *entrada = new EntradaPantallaDeSeleccionNuevo();

    pantalla->agregarEstado("sprite", sprite);
    pantalla->agregarEstado("mapa", mapa);
    pantalla->agregarComportamiento("grafico", grafico);
//    pantalla->agregarComportamiento("entrada", entrada);
}

void NivelCliente::generarSelectorDePersonaje(Mapa *mapa, Entidad *entidad) {
    Locator::logger()->log(INFO, "Se genera selector de personaje.");

}

void NivelCliente::generarJugador(Mapa *mapa, IdEntidad idEntidad, Entidad *jugador) {
    Locator::logger()->log(INFO, "Se genera jugador.");
    SDL_Renderer *sdlRenderer = Locator::renderer();

    auto *fabricaDeAnimaciones = new FabricaDeAnimacionesDeCody();
    auto *spriteJugador = new Sprite(sdlRenderer, "assets/personajes/cody.png");
    auto *animacion = fabricaDeAnimaciones->reposando();
    auto *grafico = new Grafico();
//    EstadoDePersonaje *estado = new Reposando();
//    auto *entradaJugador = new EntradaJugador();

//    jugador->agregarEstado("estado", estado);
//    jugador->agregarComportamiento("entrada jugador", entradaJugador);
    jugador->agregarEstado("sprite", spriteJugador);
    jugador->agregarEstado("animacion", animacion);
    jugador->agregarEstado("fabrica de animaciones", fabricaDeAnimaciones);
    jugador->agregarComportamiento("grafico", grafico);
}

void NivelCliente::generarEscenario(Mapa *mapa, Entidad *escenario) {
    Configuracion *config = Locator::configuracion();

    auto *nivelEstado = escenario->getEstado<Nivel>("nivel");
    string nivel = nivelEstado->nivel();
    Locator::logger()->log(DEBUG, "Se genera escenario para " + nivel);

    string srcSprite = config->getValue("/niveles/" + nivel + "/escenario/sprite/src");
//    int profundidad = config->getIntValue("/niveles/" + nivel + "/escenario/profundidad");
    int anchoNivel = config->getIntValue("/niveles/" + nivel + "/escenario/ancho");
    int cantidadDeCapas = config->getIntValue("/niveles/" + nivel + "/escenario/sprite/capas/cantidad");

//    Locator::logger()->log(DEBUG, "Se cargo profundidad para escenario: " + to_string(profundidad));
    Locator::logger()->log(DEBUG, "Se cargo ancho para escenario: " + to_string(anchoNivel));
    Locator::logger()->log(DEBUG, "Se cargo cantidad de capas para escenario: " + to_string(cantidadDeCapas));

    auto* sdlRenderer = Locator::renderer();
    auto *sprite = new Sprite(sdlRenderer, srcSprite);

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
