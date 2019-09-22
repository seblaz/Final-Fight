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


//DECLARACION CONSTANTES
static const char *const PATH_SPRITE_CAJA = "assets/escenarios/caja.png";
static const char *const PATH_SPRITE_CUCHILLO = "assets/objetos/cuchillo.png";

static const char *const PATH_XML_CANTIDAD_CAJA = "/escenario/objetos/caja/cantidad";
static const char *const PATH_XML_CANTIDAD_CUCHILLO = "/escenario/objetos/cuchillo/cantidad";



int generarPosicionX(int limiteDeFrontera){
    return rand() % limiteDeFrontera;
}

int generarPosicionY(){
    return rand() % 400;
}


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
    int largoDeFrontera = 5650;
    FisicaDeFrontera fisicaDeFrontera(largoDeFrontera, &fisicaDePersonaje);
    GraficoDeFrontera graficoDeFrontera;
    Mapeable frontera(&fisicaDeFrontera, &graficoDeFrontera, &comportamientoDeEscenario);
    mapa.agregar(&frontera);


    //Generador de cajas
    int cantidadDeBarril;
    try {
        cantidadDeBarril = Locator::configuracion()->getIntValue(PATH_XML_CANTIDAD_CAJA);
        Locator::logger()->log(DEBUG,"Se encontro el path para leer la cantidad de cajas");
        Locator::logger()->log(INFO,"Se van a generar:" + to_string(cantidadDeBarril) + " cajas");
        
    } catch(std::invalid_argument){
        Locator::logger()->log(ERROR,"No se encontro el path para obtener la cantidad de cajas a generar");
        Locator::logger()->log(DEBUG,"Se generara por defecto 1 caja");
        cantidadDeBarril = 1;
    }

    Sprite spriteCaja(renderer, PATH_SPRITE_CAJA);
    SDL_Texture *spcaja = spriteCaja.getTexture();
    Animacion* animacionCaja = FabricaDeAnimacionesDeCaja::standby();
    for (int i = 1; i <= cantidadDeBarril; i++) {
        Locator::logger()->log(INFO,"Se inicia la construccion de la caja:" + to_string(i));

        FisicaDeMapeable* fisicaDeCaja = new FisicaDeMapeable(generarPosicionX(largoDeFrontera), generarPosicionY(), 0);
        GraficoDeMapeable* graficoDeCaja = new GraficoDeMapeable(fisicaDeCaja, fisicaDeEscenario, spcaja, animacionCaja);
        Mapeable* mapeable = new Mapeable(fisicaDeCaja, graficoDeCaja, &comportamientoDeEscenario);

        mapa.agregar(mapeable);
    }


    //Generador de cuchillos
    int cantidadDeCuchillos;
    try {
        cantidadDeCuchillos = Locator::configuracion()->getIntValue(PATH_XML_CANTIDAD_CUCHILLO);
        Locator::logger()->log(DEBUG,"Se encontro el path para leer la cantidad de cuchillos");
        Locator::logger()->log(INFO,"Se van a generar:" + to_string(cantidadDeCuchillos) + " cuchillos");

    } catch(std::invalid_argument){
        Locator::logger()->log(ERROR,"No se encontro el path para obtener la cantidad de cuchillos a generar");
        Locator::logger()->log(DEBUG,"Se generara por defecto 1 cuchillo");
        cantidadDeCuchillos = 1;
    }

    Sprite spriteCuchillo(renderer, PATH_SPRITE_CUCHILLO);
    SDL_Texture *spCuchillo = spriteCuchillo.getTexture();
    Animacion* animacionCuchillo = FabricaDeAnimacionesDeCuchillo::standby();

    for (int i = 1; i <= cantidadDeCuchillos; i++) {
        Locator::logger()->log(INFO,"Se inicia la construccion del cuchillo:" + to_string(i));

        FisicaDeMapeable* fisicaDeCuchillo = new FisicaDeMapeable(generarPosicionX(largoDeFrontera), generarPosicionY(), 0);
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
