#include "Juego.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../modelo/Posicion.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"
#include "../graficos/Grafico.h"
#include "../fisica/FisicaDeEscenario.h"
#include "../graficos/GraficoDeEscenario.h"
#include "../estados/Parado.h"
#include "../fisica/FisicaDePersonaje.h"
#include "../modelo/Orientacion.h"

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
    /**
     * Iniciar.
     */
    Logger* logger;
    Configuracion *config;

    if (argc == 1){
        logger = new Logger();
        Locator::provide(logger);
        config = new Configuracion();
    } else{
        if (argc == 2){
            string param = args[1];
            size_t found = param.find(".xml");

            if (found!=std::string::npos){
                logger = new Logger();
                Locator::provide(logger);
                config = new Configuracion(args[1]);
            } else{
                logger = new Logger(args[1]);
                Locator::provide(logger);
                config = new Configuracion();
            }

        }else{
            logger = new Logger(args[1]);
            Locator::provide(logger);
            config = new Configuracion(args[2]);
        }
    }
    Locator::provide(config);


    Juego juego;
    SDL_Renderer *renderer = juego.renderer();
    Locator::provide(renderer);

    Mapa &mapa = juego.mapa();

    /**
     * Crear jugador.
     */
    Entidad * jugador = mapa.crearEntidad();

    auto * posicionDeJugador = new Posicion(200, 100, 0);
    jugador->agregarEstado("posicion", posicionDeJugador);

    auto * velocidadDeJugador = new Velocidad();
    jugador->agregarEstado("velocidad", velocidadDeJugador);

    auto * spriteJugador = new Sprite(renderer, "assets/personajes/cody.png");
    jugador->agregarEstado("sprite", spriteJugador);

    auto *orientacionDeJugador = new Orientacion;
    jugador->agregarEstado("orientacion", orientacionDeJugador);

    auto *animacionDeJugador = FabricaDeAnimacionesDeCody::parado();
    jugador->agregarEstado("animacion", animacionDeJugador);

    EstadoDePersonaje * estadoDeJugador = new Parado();
    jugador->agregarComportamiento("estado", estadoDeJugador);

    auto * fisicaDeJugador = new FisicaDePersonaje();
    jugador->agregarComportamiento("fisica", fisicaDeJugador);

    auto * graficoDeJugador = new Grafico();
    jugador->agregarComportamiento("grafico", graficoDeJugador);

    /**
     * Crear escenario.
     */
    Entidad * escenario = mapa.crearEntidad();

    auto * posicionDeEscenario = new Posicion(0, 300, 0);
    escenario->agregarEstado("posicion", posicionDeEscenario);

    auto * spriteEscenario = new Sprite(renderer, "assets/escenarios/nivel1.png");
    escenario->agregarEstado("sprite", spriteEscenario);

    auto * fisicaEscenario = new FisicaDeEscenario();
    escenario->agregarComportamiento("fisica", fisicaEscenario);

    vector<SDL_Texture *> spritesDeEscenario;
    spritesDeEscenario.push_back(spriteEscenario->getTexture());
    spritesDeEscenario.push_back(spriteEscenario->getTexture());
    spritesDeEscenario.push_back(spriteEscenario->getTexture());

    vector<SDL_Rect> posicionesSprite;
    posicionesSprite.push_back({0, 400, 0, 400});
    posicionesSprite.push_back({0, 200, 0, 195});
    posicionesSprite.push_back({0, 0, 0, 195});

    vector<float> distanciasAlFondo = {0.1, 0.5, 1};

    auto* graficoDeEscenario = new GraficoDeEscenario(spritesDeEscenario, posicionesSprite, distanciasAlFondo,
                                          spriteEscenario->ancho());
    escenario->agregarComportamiento("grafico", graficoDeEscenario);

    /**
     * Dependencias.
     */
    escenario->agregarEstado("posicion de jugador", posicionDeJugador);
    jugador->agregarEstado("posicion de escenario", posicionDeEscenario);

    /**
     * Caja.
     */
    Entidad * caja = mapa.crearEntidad();

    auto * posicionDeCaja = new Posicion(500, 150, 0);
    caja->agregarEstado("posicion", posicionDeCaja);

    auto * spriteCaja = new Sprite(renderer, "assets/escenarios/caja.png");
    caja->agregarEstado("sprite", spriteCaja);

    vector<SDL_Rect> posiciones = {{8, 5, 70, 120}};
    vector<float> duraciones = {1};
    auto* animacionDeCaja = new Animacion(posiciones, duraciones, 1, 3);
    caja->agregarEstado("animacion", animacionDeCaja);

    auto * graficoDeCaja = new Grafico();
    caja->agregarComportamiento("grafico", graficoDeCaja);
    caja->agregarEstado("posicion de escenario", posicionDeEscenario);

    /**
     * Cuchillo.
     */
    Entidad * cuchillo = mapa.crearEntidad();

    auto * spriteCuchillo = new Sprite(renderer, "assets/objetos/cuchillo.png");
    cuchillo->agregarEstado("sprite", spriteCuchillo);

    vector<SDL_Rect> posicionesCuchillo = {{8, 5, 30, 20}};
    vector<float> duracionesCuchillo = {1};
    auto* animacionCuchillo = new  Animacion(posicionesCuchillo, duracionesCuchillo, 1, 3);
    cuchillo->agregarEstado("animacion", animacionCuchillo);

    auto* posicionCuchillo = new Posicion(100, 50, 0);
    cuchillo->agregarEstado("posicion", posicionCuchillo);

    auto * graficoDeCuchillo = new Grafico();
    cuchillo->agregarComportamiento("grafico", graficoDeCuchillo);

    cuchillo->agregarEstado("posicion de escenario", posicionDeEscenario);

    /**
     * Generacion random.
     */
    int largoDeFrontera = 5650;

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

    /**
     * Caja.
     */
//    Entidad * cajaRandom = mapa.crearEntidad();
//
//    auto * posicionDeCajaRandom = new Posicion(500, 150, 0);
//    cajaRandom->agregarEstado("posicion", posicionDeCaja);
//
//    auto * spriteCaja = new Sprite(renderer, "assets/escenarios/cajaRandom.png");
//    cajaRandom->agregarEstado("sprite", spriteCaja);
//
//    vector<SDL_Rect> posiciones = {{8, 5, 70, 120}};
//    vector<float> duraciones = {1};
//    auto* animacionDeCaja = new Animacion(posiciones, duraciones, 1, 3);
//    cajaRandom->agregarEstado("animacion", animacionDeCaja);
//
//    auto * graficoDeCaja = new Grafico();
//    cajaRandom->agregarComportamiento("grafico", graficoDeCaja);
//    cajaRandom->agregarEstado("posicion de escenario", posicionDeEscenario);
//
//    Sprite spriteCaja(renderer, PATH_SPRITE_CAJA);
//    SDL_Texture *spcaja = spriteCaja.getTexture();
//    Animacion* animacionCaja = FabricaDeAnimacionesDeCaja::standby();

    for (int i = 1; i <= cantidadDeBarril; i++) {
        Locator::logger()->log(INFO,"Se inicia la construccion de la cajaRandom:" + to_string(i));

//        FisicaDeMapeable* fisicaDeCaja = new FisicaDeMapeable(generarPosicionX(largoDeFrontera), generarPosicionY(), 0);
//        GraficoDeMapeable* graficoDeCaja = new GraficoDeMapeable(fisicaDeCaja, fisicaDeEscenario, spcaja, animacionCaja);
//        Mapeable* mapeable = new Mapeable(fisicaDeCaja, graficoDeCaja, &comportamientoDeEscenario);

        Entidad* cajaRandom = mapa.crearEntidad();

        auto* posicionCajaRandom = new Posicion(generarPosicionX(largoDeFrontera), generarPosicionY(), 0);
        cajaRandom->agregarEstado("posicion", posicionCajaRandom);
        cajaRandom->agregarEstado("sprite", spriteCaja);
        cajaRandom->agregarEstado("animacion", animacionDeCaja);
        cajaRandom->agregarEstado("posicion de escenario", posicionDeEscenario);
        cajaRandom->agregarComportamiento("grafico", graficoDeCaja);
}


    juego.loop();

    delete logger;
    delete config;
}
