#include "Juego.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../modelo/Posicion.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"
#include "../niveles/Nivel.h"

//DECLARACION CONSTANTES
static const char *const PATH_SPRITE_CAJA = "assets/escenarios/caja.png";
static const char *const PATH_SPRITE_CUCHILLO = "assets/objetos/cuchillo.png";

static const char *const PATH_XML_CANTIDAD_CAJA = "/escenario/objetos/caja/cantidad";
static const char *const PATH_XML_CANTIDAD_CUCHILLO = "/escenario/objetos/cuchillo/cantidad";


int main(int argc, char *args[]) {
    /**
     * Iniciar.
     */
 bool defaultLogger = argc == 1;
    bool defaultConfiguration = argc == 1;

    if (argc == 2){
        string param = args[1];
        size_t found = param.find(".xml");

        defaultConfiguration = found==std::string::npos;
        defaultLogger = found!=std::string::npos;
    }

    Configuracion *config =
            defaultConfiguration ?
            new Configuracion() :
                (argc == 2 ?
                    new Configuracion(args[1]) :
                    new Configuracion(args[2]));

    Locator::provide(config);

    string loggerLevel = config->getValue("/debug/level");
    defaultLogger = defaultLogger && loggerLevel.compare("") == 0;

    Logger* logger =
            defaultLogger ?
            new Logger() :
            (argc == 2 ?
                new Logger(args[1]) :
                new Logger(loggerLevel));
    Locator::provide(logger);


    Juego juego;
    SDL_Renderer *renderer = juego.renderer();
    Locator::provide(renderer);
    Mapa &mapa = juego.mapa();

    //Leemos los valores de objetos
    int cantidadDeCajas;
    try {
        cantidadDeCajas = Locator::configuracion()->getIntValue(PATH_XML_CANTIDAD_CAJA);
        Locator::logger()->log(DEBUG,"Se encontro el path para leer la cantidad de cajas");
        Locator::logger()->log(INFO,"Se van a generar:" + to_string(cantidadDeCajas) + " cajas");

    } catch(std::invalid_argument){
        Locator::logger()->log(ERROR,"No se encontro el path para obtener la cantidad de cajas a generar");
        Locator::logger()->log(DEBUG,"Se generara por defecto 1 caja");
        cantidadDeCajas = 1;
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


    Nivel::generarNivel(renderer,&mapa, cantidadDeCajas, cantidadDeCuchillos);


    juego.loop();

    delete logger;
    delete config;
}
