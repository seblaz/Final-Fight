#include "Juego.h"
#include "../comportamiento/ComportamientoDeJugador.h"
#include "../graficos/GraficoDeEscenario.h"
#include "../graficos/GraficoDePersonaje.h"
#include "../fisica/FisicaDeMapeable.h"
#include "../comportamiento/ComportamientoNulo.h"
#include "../graficos/sprite/Sprite.h"
#include "../comportamiento/ComportamientoDeEnemigo.h"
#include "../graficos/GraficoDeFrontera.h"
#include "../niveles/Nivel1.h"
#include "../fisica/FisicaDeFrontera.h"

int main(int argc, char *args[]) {

    auto *logger = new Logger(args[1]);
    Locator::provide(logger);

    auto *config = new Configuracion(args[2]);
    Locator::provide(config);

    Juego juego;
    Mapa &mapa = juego.mapa();
    SDL_Renderer *renderer = juego.renderer();

    // Agregar personaje
//    Animacion *animacionDeJugador = FabricaDeAnimacionesDeCody::caminado();
//    FisicaDePersonaje fisicaDePersonaje(400);
//
//    FisicaDeEscenario fisicaDeEscenario(&fisicaDePersonaje, config->getFloatValue("/escala/escenario/ancho") * 990);//spriteEscenario.ancho());
//
//    Sprite sprite(renderer, "assets/personajes/cody.png");
//    ComportamientoDeJugador comportamientoDeJugador(&fisicaDePersonaje);
//    GraficoDePersonaje graficoDePersonaje(&fisicaDePersonaje, fisicaDeEscenario, sprite.getTexture(), animacionDeJugador,
//                                          &comportamientoDeJugador);
//    Mapeable personaje(&fisicaDePersonaje, &graficoDePersonaje, &comportamientoDeJugador);
//
//    mapa.agregarJugador(&personaje);

//    Nivel1::generarNivel(mapa, renderer);
    // Sprites
    Sprite spriteEscenario(renderer, "assets/escenarios/nivel1.png");
    Sprite spriteCaja(renderer, "assets/escenarios/caja.png");
    Sprite spriteCuchillo(renderer, "assets/objetos/cuchillo.png");

    // Agregar personaje
    Animacion *animacion = FabricaDeAnimacionesDeCody::caminado();
    FisicaDePersonaje fisicaDePersonaje(400);

    FisicaDeEscenario fisicaDeEscenario(&fisicaDePersonaje, config->getFloatValue("/escala/escenario/ancho") * spriteEscenario.ancho());

    Sprite sprite(renderer, "assets/personajes/cody.png");
    ComportamientoDeJugador comportamientoDeJugador(&fisicaDePersonaje);
    GraficoDePersonaje graficoDePersonaje(&fisicaDePersonaje, fisicaDeEscenario, sprite.getTexture(), animacion,
                                          &comportamientoDeJugador);
    Mapeable personaje(&fisicaDePersonaje, &graficoDePersonaje, &comportamientoDeJugador);

    // Agregar escenario (primera capa)
    vector<SDL_Texture *> spritesDeEscenario;
    spritesDeEscenario.push_back(spriteEscenario.getTexture());
    spritesDeEscenario.push_back(spriteEscenario.getTexture());
    spritesDeEscenario.push_back(spriteEscenario.getTexture());

    vector<SDL_Rect> posicionesSprite;
    posicionesSprite.push_back({0, 400, 0, 400});
    posicionesSprite.push_back({0, 200, 0, 195});
    posicionesSprite.push_back({0, 0, 0, 195});

    vector<float> distanciasAlFondo = {0.1, 0.5, 1};

    GraficoDeEscenario graficoDeEscenario(fisicaDeEscenario, spritesDeEscenario, posicionesSprite, distanciasAlFondo,
                                          spriteEscenario.ancho());
    ComportamientoNulo comportamientoDeEscenario;
    Mapeable escenarioFondo(&fisicaDeEscenario, &graficoDeEscenario, &comportamientoDeEscenario);
    mapa.agregar(&escenarioFondo);

    // Agregar frontera.
    FisicaDeFrontera fisicaDeFrontera(5650, &fisicaDePersonaje);
    GraficoDeFrontera graficoDeFrontera;
    Mapeable frontera(&fisicaDeFrontera, &graficoDeFrontera, &comportamientoDeEscenario);
    mapa.agregar(&frontera);

    // Caja
    vector<SDL_Rect> posiciones = {{8, 5, 70, 120}};
    vector<float> duraciones = {1};
    Animacion animacionDeCaja(posiciones, duraciones, 1, 3);

    FisicaDeMapeable fisicaDeObjeto(500, 200, 0);
    SDL_Texture *spcaja = spriteCaja.getTexture();
    GraficoDeMapeable graficoDeObjeto(&fisicaDeObjeto, fisicaDeEscenario, spcaja, animacionDeCaja);
    Mapeable caja(&fisicaDeObjeto, &graficoDeObjeto, &comportamientoDeEscenario);
    mapa.agregar(&caja);

    //CUchillo

    vector<SDL_Rect> posicionesCuchillo = {{8, 5, 30, 20}};
    vector<float> duracionesCuchillo = {1};
    Animacion animacionDeCuchillo(posicionesCuchillo, duracionesCuchillo, 1, 3);

    FisicaDeMapeable fisicaDeCuchillo(500, 200, 0);
    SDL_Texture *spCuchillo = spriteCuchillo.getTexture();
    GraficoDeMapeable graficoDeCuchillo(&fisicaDeCuchillo, fisicaDeEscenario, spCuchillo, animacionDeCuchillo);

    Mapeable cuchillo(&fisicaDeCuchillo, &graficoDeCuchillo, &comportamientoDeEscenario);
    mapa.agregar(&cuchillo);

    mapa.agregar(&personaje);

    // Agregar enemigo
    FabricaDeAnimacionesDePoison fabricaDeAnimacionesDePoison;
    Animacion *animacionInicialPoison = FabricaDeAnimacionesDePoison::caminando();
    FisicaDePersonaje fisicaDePersonajePoison(500, 40, 0);

    Sprite spritePoison(renderer, "assets/personajes/poison.png");
    ComportamientoDeEnemigo comportamientoDeEnemigo(&fisicaDePersonajePoison);
    GraficoDePersonaje graficoDeEnemigo(&fisicaDePersonajePoison,
                                        fisicaDeEscenario, spritePoison.getTexture(), animacionInicialPoison,
                                        &comportamientoDeEnemigo);
    Mapeable enemigo(&fisicaDePersonajePoison, &graficoDeEnemigo, &comportamientoDeEnemigo);
    mapa.agregar(&enemigo);


    juego.loop();

    delete logger;
    delete config;
}
