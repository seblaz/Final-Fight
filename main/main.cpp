#include "Juego.h"
#include "../servicios/Locator.h"
#include "../graficos/Sprite.h"
#include "../modelo/Posicion.h"
#include "../graficos/animaciones/FabricaDeAnimacionesDeCody.h"
#include "../niveles/Nivel.h"
#include "../tipos/tipos.h"

void configApplication(int argc, const char*args[]){
    bool defaultLogger = argc == 1;
    bool defaultConfiguration = argc == 1;
    bool paramIsLoggerLevel = false;

    if (argc == 2){
        string param = args[1];
        size_t found = param.find(".xml");

        defaultConfiguration = found==std::string::npos;
        defaultLogger = found!=std::string::npos;
        paramIsLoggerLevel = !defaultLogger;
    }

    auto* logger = new Logger();
    Locator::provide(logger);

    Configuracion *config =
            defaultConfiguration ?
            new Configuracion() :
            (argc == 2 ?
             new Configuracion(args[1]) :
             new Configuracion(args[2]));

    Locator::provide(config);

    string loggerLevel = config->getValue("/debug/level");
    defaultLogger = defaultLogger && loggerLevel.empty();

    if (!defaultLogger){
        string newLevel = (argc > 2 || paramIsLoggerLevel) ? args[1] : loggerLevel;
        Locator::logger()->setLevel(newLevel);
    }

    string configPath = config->getActualPath();

    Locator::logger()->log(INFO, "Archivo de configuracion abierto: " + configPath);
}

int main(int argc, const char **args) {
    /**
     * Iniciar.
     */

    if (argc == 1){
        const char *args2[] = {"", "DEBUG", "Configuracion.xml"};
        configApplication(1, args2);
    }else{
        configApplication(argc, args);
    }

    Juego juego;
    SDL_Renderer *renderer = juego.renderer();
    Locator::provide(renderer);

    Mapa &mapa = juego.mapa();

    nombreJugador nombreJugador = juego.menuPrincipal();

    Entidad *jugador = Nivel::generarJugador(&mapa, nombreJugador);

    Nivel::generarNivel("nivel1", &mapa, jugador);

    juego.loop();
    juego.terminar();

    Locator::clean();
}