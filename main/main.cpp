#include "Juego.h"
#include "../comportamiento/ComportamientoDeJugador.h"
#include "../servicios/Logger.h"
#include "../servicios/Locator.h"
#include "../graficos/GraficoDeEscenario.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../graficos/GraficoDePersonaje.h"
#include "../fisica/FisicaDeMapeable.h"
#include "../comportamiento/ComportamientoNulo.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"
#include "../graficos/FabricaDeAnimacionesDePoison.h"
#include "../graficos/sprite/Sprite.h"
#include "../graficos/GraficoDeMapeable.h"
#include "../comportamiento/ComportamientoDeEnemigo.h"
#include <cmath>

int main(int argc, char *args[]) {
    auto *logger = new Logger(DEBUG);
    Locator::provide(logger);

    auto *config = new Configuracion(1280, 960, 1, 1, M_PI * 0.18);
    Locator::provide(config);

    Mapa mapa(300, 1000, 500);
    Juego juego(&mapa);
    SDL_Renderer *renderer = juego.renderer();

    Sprite spriteEscenario(renderer, "assets/escenarios/slums-mejorado.png");
    Sprite spriteCaja(renderer, "assets/escenarios/caja.png");
    Sprite spriteNeumatico(renderer, "assets/escenarios/neumaticos.png");

    // Agregar personaje
    Animacion animacion = FabricaDeAnimacionesDeCody::caminado();
    FisicaDePersonaje fisicaDePersonaje(500);

    FisicaDeEscenario fisicaDeEscenario(fisicaDePersonaje);

    Sprite sprite(renderer, "assets/personajes/cody.png");
    GraficoDePersonaje graficoDePersonaje(&fisicaDePersonaje, fisicaDeEscenario, sprite.getTexture(), animacion);
    ComportamientoDeJugador comportamientoDeJugador(&fisicaDePersonaje);
    Mapeable personaje(&fisicaDePersonaje, &graficoDePersonaje, &comportamientoDeJugador);

    // Agregar escenario (primera capa)
    vector<SDL_Texture*> spritesDeEscenario;
    spritesDeEscenario.push_back(spriteEscenario.getTexture());
    spritesDeEscenario.push_back(spriteEscenario.getTexture());

    vector<SDL_Rect> posicionesSprite;
    posicionesSprite.push_back({0, 200, 250, 195});
    posicionesSprite.push_back({0, 0, 250, 195});

    vector<float> distanciasAlFondo = {0.5, 1};

    GraficoDeEscenario graficoDeEscenario(fisicaDeEscenario, spritesDeEscenario, posicionesSprite, distanciasAlFondo);
    ComportamientoNulo comportamientoDeEscenario;
    Mapeable escenarioFondo(&fisicaDeEscenario, &graficoDeEscenario, &comportamientoDeEscenario);
    mapa.agregar(&escenarioFondo);

    // Caja
    vector<SDL_Rect> posiciones = {{8, 5, 49, 80}};
    vector<float> duraciones = {1};
    Animacion animacionDeCaja(posiciones, duraciones, 1, 3);

    FisicaDeMapeable fisicaDeObjeto(500, 400, 0);
    SDL_Texture * spcaja = spriteCaja.getTexture();
    GraficoDeMapeable graficoDeObjeto(&fisicaDeObjeto, fisicaDeEscenario, spcaja, animacionDeCaja);

    Mapeable caja(&fisicaDeObjeto, &graficoDeObjeto, &comportamientoDeEscenario);
    mapa.agregar(&caja);


//    FisicaDeMapeable fisicaDeObjetoDestruible;
//    // Objetos (objeto caja)
//     GraficoDeObjeto graficoDeObjetoCaja(renderer, spriteCaja.getTexture(), 800,400);
//
//     Objeto objetoCaja(0, 0, 0, &mapa, &fisicaDeObjetoDestruible, &graficoDeObjetoCaja);
//     mapa.agregar(&objetoCaja);
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

    mapa.agregar(&personaje);

    // Agregar enemigo
    FabricaDeAnimacionesDePoison fabricaDeAnimacionesDePoison;
    Animacion animacionInicialPoison = FabricaDeAnimacionesDePoison::caminando();
    FisicaDePersonaje fisicaDePersonajePoison(500,40,0);

    Sprite spritePoison(renderer, "assets/personajes/poison.png");
    GraficoDePersonaje graficoDeEnemigo(&fisicaDePersonajePoison,
                                        fisicaDeEscenario, spritePoison.getTexture(), animacionInicialPoison);
    ComportamientoDeEnemigo comportamientoDeEnemigo(&fisicaDePersonajePoison);
    Mapeable enemigo(&fisicaDePersonajePoison, &graficoDeEnemigo, &comportamientoDeEnemigo);
    mapa.agregar(&enemigo);


    juego.loop();

    delete logger;
    delete config;
}
