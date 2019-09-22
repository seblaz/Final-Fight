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
#include "../graficos/FabricaDeAnimacionesDeCaja.h"
#include "../graficos/FabricaDeAnimacionesDeCuchillo.h"

static const char *const PATH_XML_CANTIDAD_CAJA = "/escenario/barril/cantidad";
static const char *const PATH_XML_CANTIDAD_CUCHILLO = "/escenario/objetos/cuchillo/cantidad";

int main(int argc, char *args[]) {
    auto *logger = new Logger(DEBUG);
    Locator::provide(logger);

    string configurationPath;
    cout << "Ingrese la ruta de archivo de configuracion.\n";
    cin >> configurationPath;

    auto *config = new Configuracion(configurationPath);
    Locator::provide(config);

    Juego juego;
    Mapa &mapa = juego.mapa();
    SDL_Renderer *renderer = juego.renderer();


    Sprite spriteEscenario(renderer, "assets/escenarios/nivel1.png");



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

;

    //Generador de cajas
    int cantidadDeBarril;
    try {
        cantidadDeBarril = Locator::configuracion()->getIntValue(PATH_XML_CANTIDAD_CAJA);
        Locator::logger()->log(DEBUG,"Se encontro el path para leer la cantidad de cajas");
        Locator::logger()->log(INFO,"Se van a generar:" + to_string(cantidadDeBarril) + " cajas");
        
    } catch(std::invalid_argument){
        Locator::logger()->log(ERROR,"No se encontro el path para obtener el path");
        Locator::logger()->log(DEBUG,"Se generara por defecto 1 caja");
        cantidadDeBarril = 1;
    }

    Sprite spriteCaja(renderer, "assets/escenarios/caja.png");
    SDL_Texture *spcaja = spriteCaja.getTexture();
    Animacion* animacionCaja = FabricaDeAnimacionesDeCaja::standby();
    for (int i = 1; i <= cantidadDeBarril; i++) {
        Locator::logger()->log(INFO,"Se inicia la construccion de la caja:" + to_string(i));

        FisicaDeMapeable* fisicaDeCaja = new FisicaDeMapeable(500 + i*200, 200, 0);
        GraficoDeMapeable* graficoDeCaja = new GraficoDeMapeable(fisicaDeCaja, fisicaDeEscenario, spcaja, animacionCaja);
        Mapeable* mapeable = new Mapeable(fisicaDeCaja, graficoDeCaja, &comportamientoDeEscenario);

        mapa.agregar(mapeable);
    }



    //Generador de cuchillos


    Sprite spriteCuchillo(renderer, "assets/objetos/cuchillo.png");
    SDL_Texture *spCuchillo = spriteCuchillo.getTexture();
    Animacion* animacionCuchillo = FabricaDeAnimacionesDeCuchillo::standby();

    int cantidadDeCuchillos = Locator::configuracion()->getIntValue(PATH_XML_CANTIDAD_CUCHILLO);
    Locator::logger()->log(DEBUG,"Cantidad de chucillos a construir:" + to_string(cantidadDeBarril));

    for (int i = 1; i <= cantidadDeBarril; i++) {
        Locator::logger()->log(INFO,"Se inicia la construccion del cuchillo:" + to_string(i));

        FisicaDeMapeable* fisicaDeCuchillo = new FisicaDeMapeable(200 + i*200, 0, 0);
        GraficoDeMapeable* graficoDeCuchillo = new GraficoDeMapeable(fisicaDeCuchillo, fisicaDeEscenario, spCuchillo, animacionCuchillo);
        Mapeable* mapeable = new Mapeable(fisicaDeCuchillo, graficoDeCuchillo, &comportamientoDeEscenario);

        mapa.agregar(mapeable);
    }

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
