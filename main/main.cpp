#include "Juego.h"
#include "../graficos/GraficoDePersonaje.h"
#include "../modelo/mapeables/Personaje.h"
#include "../comportamiento/ComportamientoDeJugador.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../servicios/Logger.h"
#include "../servicios/Locator.h"
#include "../graficos/GraficoDeEscenario.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../modelo/mapeables/Escenario.h"

int main(int argc, char *args[]) {
    auto *logger = new Logger(DEBUG);
    Locator::provide(logger);

    Mapa mapa(300, 1000, 500);
    Juego juego(&mapa);
    SDL_Renderer* renderer = juego.renderer();

    // Agregar escenario
    GraficoDeEscenario graficoDeEscenario(renderer, "assets/escenarios/slums.png");
    FisicaDeEscenario fisicaDeEscenario;
    Escenario escenario(0, 0, 0, &mapa, &fisicaDeEscenario, &graficoDeEscenario);
    mapa.agregar(&escenario);

    // Agregar personaje
    GraficosDePersonaje graficoDePersonaje(renderer, "assets/personajes/coddy.png");
    ComportamientoDeJugador comportamientoDeJugador;
    FisicaDePersonaje fisicaDePersonaje;
    Personaje personaje(1, 1, 0, "sebas", &mapa, &comportamientoDeJugador, &fisicaDePersonaje, &graficoDePersonaje);
    mapa.agregar(&personaje);


    juego.loop();

    delete(logger);
}
