#include "Juego.h"
#include "../graficos/GraficoDePersonajeParado.h"
#include "../modelo/mapeables/Personaje.h"
#include "../comportamiento/ComportamientoDeJugador.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../servicios/Logger.h"
#include "../servicios/Locator.h"
#include "../graficos/GraficoDeEscenario.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../modelo/mapeables/Escenario.h"
#include "../graficos/sprite/Sprite.h"
#include "../graficos/GraficoDePersonajeCaminando.h"
#include <cmath>

int main(int argc, char *args[]) {
    auto *logger = new Logger(DEBUG);
    Locator::provide(logger);

    auto *config = new Configuracion(1280, 960, 1, 4.5, M_PI*0.25);
    Locator::provide(config);

    Mapa mapa(300, 1000, 500);
    Juego juego(&mapa);
    SDL_Renderer* renderer = juego.renderer();

//    Sprite spriteEscenario(renderer,"assets/escenarios/slums.png");
    Sprite spriteEscenario(renderer,"assets/escenarios/slums-mejorado.png");
    Sprite spritePersonaje(renderer,"assets/personajes/coddy.png");


    // Agregar escenario (primera capa)
    GraficoDeEscenario graficoDeEscenarioFondo(renderer, spriteEscenario.getTexture(),200);
    FisicaDeEscenario fisicaDeEscenarioFondo;
    Escenario escenarioFondo(0, 200, 0, &mapa, &fisicaDeEscenarioFondo, &graficoDeEscenarioFondo);
    mapa.agregar(&escenarioFondo);


    // Agregar escenario (segunda capa)
    GraficoDeEscenario graficoDeEscenarioMedio(renderer, spriteEscenario.getTexture(),0);
    FisicaDeEscenario fisicaDeEscenario;
    Escenario escenarioMedio(0, 0, 0, &mapa, &fisicaDeEscenario, &graficoDeEscenarioMedio);
    mapa.agregar(&escenarioMedio);


    // Agregar personaje
    GraficoDePersonajeCaminando graficoDePersonaje(renderer, spritePersonaje.getTexture());
    ComportamientoDeJugador comportamientoDeJugador;
    FisicaDePersonaje fisicaDePersonaje;
    Personaje personaje(50, 0, 0, "sebas", &mapa, &comportamientoDeJugador, &fisicaDePersonaje, &graficoDePersonaje);
    mapa.agregar(&personaje);


    juego.loop();

    delete logger;
    delete config;
}
