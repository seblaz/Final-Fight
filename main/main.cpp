#include "Juego.h"
#include "../modelo/mapeables/Personaje.h"
#include "../comportamiento/ComportamientoDeJugador.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../servicios/Logger.h"
#include "../servicios/Locator.h"
#include "../graficos/GraficoDeEscenario.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../modelo/mapeables/Escenario.h"
#include "../graficos/GraficoDePersonaje.h"
#include "../graficos/FabricaDeGraficosDeCody.h"
#include "../graficos/GraficoDeObjeto.h"
#include "../modelo/mapeables/Objeto.h"
#include "../fisica/FisicaDeObjeto.h"
#include <cmath>

int main(int argc, char *args[]) {
    auto *logger = new Logger(DEBUG);
    Locator::provide(logger);

    auto *config = new Configuracion(1280, 960, 1.5, 4.5, M_PI * 0.18);
    Locator::provide(config);

    Mapa mapa(300, 1000, 500);
    Juego juego(&mapa);
    SDL_Renderer *renderer = juego.renderer();

    Sprite spriteEscenario(renderer, "assets/escenarios/slums-mejorado.png");
    Sprite spriteCaja(renderer, "assets/escenarios/caja.png");
    Sprite spriteNeumatico(renderer, "assets/escenarios/neumaticos.png");

    // Agregar escenario (primera capa)
    GraficoDeEscenario graficoDeEscenarioFondo(renderer, spriteEscenario.getTexture(), 200);
    FisicaDeEscenario fisicaDeEscenarioFondo;
    Escenario escenarioFondo(0, 200, 0, &mapa, &fisicaDeEscenarioFondo, &graficoDeEscenarioFondo);
   mapa.agregar(&escenarioFondo);


    // Agregar escenario (segunda capa)
    GraficoDeEscenario graficoDeEscenarioMedio(renderer, spriteEscenario.getTexture(), 0);
    FisicaDeEscenario fisicaDeEscenario;
    Escenario escenarioMedio(0, 0, 0, &mapa, &fisicaDeEscenario, &graficoDeEscenarioMedio);
    mapa.agregar(&escenarioMedio);

    FisicaDeObjeto fisicaDeObjetoDestruible;
    // Objetos (objeto caja)
     GraficoDeObjeto graficoDeObjetoCaja(renderer, spriteCaja.getTexture(), 800,400);

     Objeto objetoCaja(0, 0, 0, &mapa, &fisicaDeObjetoDestruible, &graficoDeObjetoCaja);
     mapa.agregar(&objetoCaja);


    // Objetos (objeto neumatico)
    GraficoDeObjeto graficoDeObjetoNeumatico(renderer, spriteNeumatico.getTexture(), 600,400);
    Objeto objetoNeumatico(0, 0, 0, &mapa, &fisicaDeObjetoDestruible, &graficoDeObjetoNeumatico);
    mapa.agregar(&objetoNeumatico);

    GraficoDeObjeto graficoDeObjetoNeumatico2(renderer, spriteNeumatico.getTexture(), 500,400);
    Objeto objetoNeumatico2(0, 0, 0, &mapa, &fisicaDeObjetoDestruible, &graficoDeObjetoNeumatico2);
    mapa.agregar(&objetoNeumatico2);


    // Agregar personaje
    FabricaDeGraficosDeCody fabrica(renderer);
    GraficoDePersonaje graficoDePersonaje = fabrica.caminado();
    ComportamientoDeJugador comportamientoDeJugador;
    FisicaDePersonaje fisicaDePersonaje;
    Personaje personaje(50, 0, 0, "sebas", false, &mapa, &comportamientoDeJugador, &fisicaDePersonaje, &graficoDePersonaje);
    mapa.agregar(&personaje);


    juego.loop();

    delete logger;
    delete config;
}
