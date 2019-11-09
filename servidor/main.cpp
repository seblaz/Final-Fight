//
// Created by sebas on 4/10/19.
//

#include "ConexionServidor.h"
#include "../servicios/Locator.h"
#include "ConexionesClientes.h"
#include "Procesamiento.h"
#include "GameLoop.h"

using namespace std;

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

    if (argc == 1){
        const char *args2[] = {"", "DEBUG", "Configuracion.xml"};
        configApplication(1, args2);
    }else{
        configApplication(argc, args);
    }
    /**
     * Conexion al servidor.
     */
    ConexionServidor conexion(5000);
    Socket *socketServidor = conexion.socket();

    /**
     * Crear el mapa.
     */
    Mapa mapa;
    Locator::provide(&mapa);

    /**
    * Crear colisionables.
    */
    Colisionables colisionables;
    Locator::provide(&colisionables);

    /**
     * Procesamiento.
     */
    Procesamiento procesamiento;
    auto *eventosAProcesar = procesamiento.devolverCola();
    pthread_t hiloProcesamiento = procesamiento.procesarEnHilo();
    Locator::provide(eventosAProcesar);

    /**
     * Manager de usuarios.
     */
    int maximoJugadores = Locator::configuracion()->getIntValue("/jugadores/cantidad");
    ManagerUsuarios managerUsuarios(maximoJugadores);
    Locator::provide(&managerUsuarios);
    Locator::logger()->log(INFO, "Esperando " + to_string(maximoJugadores) + " jugador(es).");

    /**
     * Conexiones de clientes.
     */
    ConexionesClientes conexiones(socketServidor);
    pthread_t hiloConexiones = conexiones.manejarConexionesEnHilo();

    GameLoop gameLoop;
    try {
        gameLoop.loop();
    } catch (const out_of_range& e) {
        Locator::logger()->log(ERROR, "Ocurrió una excepción: " + string(e.what()));
        exit(0);
    }


    /**
     * Termino el procesamiento.
     */
    procesamiento.finalizar();
    pthread_join(hiloProcesamiento, nullptr);
    
    socketServidor->finalizarConexion();
    pthread_join(hiloConexiones, nullptr);

    Locator::logger()->log(INFO, "Fin del programa.");
    return 0;
}

