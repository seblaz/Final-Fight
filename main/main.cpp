#include "Juego.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../modelo/Posicion.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"
#include "../niveles/Nivel.h"

void configApplication(int argc, char*args[]){
    bool defaultLogger = argc == 1;
    bool defaultConfiguration = argc == 1;
    bool paramIsLoggerLevel;

    if (argc == 2){
        string param = args[1];
        size_t found = param.find(".xml");

        defaultConfiguration = found==std::string::npos;
        defaultLogger = found!=std::string::npos;
        paramIsLoggerLevel = !defaultLogger;
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
            (argc > 2 || paramIsLoggerLevel ?
             new Logger(args[1]) :
             new Logger(loggerLevel));
    Locator::provide(logger);

    string loggerMsj =
            defaultLogger ?
            "Se inicio logger configurado por default." :
            "Se inicio logger configurado por usuario.";
    Locator::logger()->log(DEBUG, loggerMsj);

    string configMsj =
            defaultConfiguration ?
            "Se intenta cargar archivo de configuracion por default." :
            "Se intenta cargar archivo de configuracion por usuario.";
    Locator::logger()->log(DEBUG, configMsj);

    logger = nullptr;
    config = nullptr;

    delete logger;
    delete config;
}

int main(int argc, char *args[]) {
    /**
     * Iniciar.
     */
    configApplication(argc, args);

    Juego juego;
    SDL_Renderer *renderer = juego.renderer();
    Locator::provide(renderer);

    Mapa &mapa = juego.mapa();

    Entidad *jugador = Nivel::generarJugador(&mapa);

    Nivel::generarNivel("nivel1", &mapa, jugador);

    juego.loop();

    Locator::clean();
}