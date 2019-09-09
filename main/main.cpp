#include "Juego.h"
#include "../graficos/GraficoDePersonaje.h"
#include "../modelo/mapeables/Personaje.h"
#include "../comportamiento/ComportamientoDeJugador.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../servicios/Logger.h"
#include "../servicios/Locator.h"

int main(int argc, char *args[]) {
    auto *logger = new Logger(DEBUG);
    Locator::provide(logger);

    Mapa mapa(300, 1000, 500);
    Juego juego(&mapa);
    SDL_Renderer* renderer = juego.renderer();

    GraficosDePersonaje graficoDePersonaje(renderer, "assets/personajes/coddy.png");
    ComportamientoDeJugador comportamientoDeJugador;
    FisicaDePersonaje fisicaDePersonaje;
    Personaje personaje(1, 1, 0, "sebas", &mapa, &comportamientoDeJugador, &fisicaDePersonaje, &graficoDePersonaje);

    mapa.agregar(&personaje);

    juego.loop();

    delete(logger);
}
