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

    auto *config = new Configuracion(1600, 900, 1, 1, M_PI * 0.18);
    Locator::provide(config);

    Mapa mapa(300, 100, 500);
    Juego juego(&mapa);
    SDL_Renderer *renderer = juego.renderer();

    Sprite spriteEscenario(renderer, "assets/escenarios/nivel1.png");

    Sprite spriteCaja(renderer, "assets/escenarios/caja.png");
    Sprite spriteCuchillo(renderer, "assets/objetos/cuchillo.png");

    // Agregar personaje
    Animacion *animacion = FabricaDeAnimacionesDeCody::caminado();
    FisicaDePersonaje fisicaDePersonaje(400);

    FisicaDeEscenario fisicaDeEscenario(fisicaDePersonaje, 5650);

    Sprite sprite(renderer, "assets/personajes/cody.png");
    ComportamientoDeJugador comportamientoDeJugador(&fisicaDePersonaje);
    GraficoDePersonaje graficoDePersonaje(&fisicaDePersonaje, fisicaDeEscenario, sprite.getTexture(), animacion, &comportamientoDeJugador);
    Mapeable personaje(&fisicaDePersonaje, &graficoDePersonaje, &comportamientoDeJugador);

    // Agregar escenario (primera capa)
    vector<SDL_Texture*> spritesDeEscenario;
    spritesDeEscenario.push_back(spriteEscenario.getTexture());
    spritesDeEscenario.push_back(spriteEscenario.getTexture());
    spritesDeEscenario.push_back(spriteEscenario.getTexture());

    vector<SDL_Rect> posicionesSprite;
    posicionesSprite.push_back({0, 400, 280, 400});
    posicionesSprite.push_back({0, 200, 280, 195});
    posicionesSprite.push_back({0, 0, 280, 195});

    vector<float> distanciasAlFondo = {0.1, 0.5, 1 };

    GraficoDeEscenario graficoDeEscenario(fisicaDeEscenario, spritesDeEscenario, posicionesSprite, distanciasAlFondo);
    ComportamientoNulo comportamientoDeEscenario;
    Mapeable escenarioFondo(&fisicaDeEscenario, &graficoDeEscenario, &comportamientoDeEscenario);
    mapa.agregar(&escenarioFondo);

    // Caja
    vector<SDL_Rect> posiciones = {{8, 5, 70, 120}};
    vector<float> duraciones = {1};
    Animacion animacionDeCaja(posiciones, duraciones, 1, 3);

    FisicaDeMapeable fisicaDeObjeto(500, 400, 0);
    SDL_Texture * spcaja = spriteCaja.getTexture();
    GraficoDeMapeable graficoDeObjeto(&fisicaDeObjeto, fisicaDeEscenario, spcaja, animacionDeCaja);
    Mapeable caja(&fisicaDeObjeto, &graficoDeObjeto, &comportamientoDeEscenario);
    mapa.agregar(&caja);

    //CUchillo

    vector<SDL_Rect> posicionesCuchillo = {{8, 5, 30, 20}};
    vector<float> duracionesCuchillo = {1};
    Animacion animacionDeCuchillo(posicionesCuchillo, duracionesCuchillo, 1, 3);

    FisicaDeMapeable fisicaDeCuchillo(500, 200, 0);
    SDL_Texture * spCuchillo = spriteCuchillo.getTexture();
    GraficoDeMapeable graficoDeCuchillo(&fisicaDeCuchillo, fisicaDeEscenario, spCuchillo, animacionDeCuchillo);

    Mapeable cuchillo(&fisicaDeCuchillo, &graficoDeCuchillo, &comportamientoDeEscenario);
    mapa.agregar(&cuchillo);

    mapa.agregar(&personaje);

    // Agregar enemigo
    FabricaDeAnimacionesDePoison fabricaDeAnimacionesDePoison;
    Animacion *animacionInicialPoison = FabricaDeAnimacionesDePoison::caminando();
    FisicaDePersonaje fisicaDePersonajePoison(500,40,0);

    Sprite spritePoison(renderer, "assets/personajes/poison.png");
    ComportamientoDeEnemigo comportamientoDeEnemigo(&fisicaDePersonajePoison);
    GraficoDePersonaje graficoDeEnemigo(&fisicaDePersonajePoison,
                                        fisicaDeEscenario, spritePoison.getTexture(), animacionInicialPoison, &comportamientoDeEnemigo);
    Mapeable enemigo(&fisicaDePersonajePoison, &graficoDeEnemigo, &comportamientoDeEnemigo);
    mapa.agregar(&enemigo);


    juego.loop();

    delete logger;
    delete config;
}
