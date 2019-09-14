#include "Juego.h"
#include "../comportamiento/ComportamientoDeJugador.h"
#include "../servicios/Logger.h"
#include "../servicios/Locator.h"
#include "../graficos/GraficoDeEscenario.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../graficos/GraficoDePersonaje.h"
#include "../fisica/FisicaDeObjeto.h"
#include "../comportamiento/ComportamientoNulo.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"
#include "../graficos/sprite/Sprite.h"
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
    GraficoDeEscenario graficoDeEscenarioFondo(spriteEscenario.getTexture(), 200);
    FisicaDeEscenario fisicaDeEscenarioFondo;
    ComportamientoNulo comportamientoDeEscenario;
    Mapeable escenarioFondo(&fisicaDeEscenarioFondo, &graficoDeEscenarioFondo, &comportamientoDeEscenario);
    mapa.agregar(&escenarioFondo);


    // Agregar escenario (segunda capa)
    GraficoDeEscenario graficoDeEscenarioMedio(spriteEscenario.getTexture(), 0);
    FisicaDeEscenario fisicaDeEscenario;
    Mapeable escenarioMedio(&fisicaDeEscenario, &graficoDeEscenarioMedio, &comportamientoDeEscenario);
    mapa.agregar(&escenarioMedio);

    FisicaDeObjeto fisicaDeObjetoDestruible;
    // Objetos (objeto caja)
     GraficoDeObjeto graficoDeObjetoCaja(renderer, spriteCaja.getTexture(), 800,400);

     Objeto objetoCaja(0, 0, 0, &mapa, &fisicaDeObjetoDestruible, &graficoDeObjetoCaja);
     mapa.agregar(&objetoCaja);
//
//
//    // Objetos (objeto neumatico)
//    GraficoDeObjeto graficoDeObjetoNeumatico(renderer, spriteNeumatico.getTexture(), 600,400);
//    Objeto objetoNeumatico(0, 0, 0, &mapa, &fisicaDeObjetoDestruible, &graficoDeObjetoNeumatico);
//    mapa.agregar(&objetoNeumatico);
//
//    GraficoDeObjeto graficoDeObjetoNeumatico2(renderer, spriteNeumatico.getTexture(), 500,400);
//    Objeto objetoNeumatico2(0, 0, 0, &mapa, &fisicaDeObjetoDestruible, &graficoDeObjetoNeumatico2);
//    mapa.agregar(&objetoNeumatico2);
//
//
    // Agregar personaje
    FabricaDeAnimacionesDeCody fabrica;
    Animacion animacion = fabrica.caminado();
    FisicaDePersonaje fisicaDePersonaje;
    Sprite sprite(renderer, "assets/personajes/cody.png");
    GraficoDePersonaje graficoDePersonaje(&fisicaDePersonaje, sprite.getTexture(), animacion);
    ComportamientoDeJugador comportamientoDeJugador(&fisicaDePersonaje);
    Mapeable personaje(&fisicaDePersonaje, &graficoDePersonaje, &comportamientoDeJugador);
    mapa.agregar(&personaje);


    juego.loop();

    delete logger;
    delete config;
}
