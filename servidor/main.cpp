//
// Created by sebas on 4/10/19.
//

#include "ConexionServidor.h"
#include "../servicios/Locator.h"
#include "ConexionesClientes.h"
#include "ContenedorHilos.h"
#include "Procesamiento.h"
#include "../eventos/Eventos.h"
#include "Transmision.h"
#include "../eventos/MostrarMenuSeleccion.h"
#include "../eventos/ActualizarYTransmitir.h"
#include "GameLoop.h"
#include "../usuario/ManagerUsuarios.h"

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
    int socketServidor = conexion.socket();

    /**
     * Crear el mapa.
     */
    Mapa mapa;

    /**
     * Lista de sockets
     */
     ListaSockets listaSockets;

    /**
     * Transmision.
     */
    Transmision transmision(&listaSockets);
    auto *eventosATransmitir = transmision.devolverCola();
    pthread_t hiloTransmision = transmision.transmitirEnHilo();

    /**
     * Procesamiento.
     */
    Procesamiento procesamiento;
    auto *eventosAProcesar = procesamiento.devolverCola();
    pthread_t hiloProcesamiento = procesamiento.procesarEnHilo();

    /**
     * Manager de usuarios.
     */
    int maximoJugadores = Locator::configuracion()->getIntValue("/usuarios/cantidad", 4);
    ManagerUsuarios managerUsuarios(maximoJugadores);
    Locator::logger()->log(INFO, "Esperando " + to_string(maximoJugadores) + " jugador(es).");

    /**
     * Selector de personajes.
     */
     SelectorPersonajes selector(maximoJugadores);

    /**
     * Contenedor de hilos.
     */
     ContenedorHilos contenedor(&mapa, eventosAProcesar, &managerUsuarios, &selector, &listaSockets);

    /**
     * Conexiones de clientes.
     */
    ConexionesClientes conexiones(socketServidor, &listaSockets, &managerUsuarios, &contenedor);
    pthread_t hiloConexiones = conexiones.manejarConexionesEnHilo();

    /**
     * Game loop.
     */
    auto *comenzar = new MostrarMenuSeleccion(&mapa);
    eventosAProcesar->push(comenzar);

    auto *actualizar = new ActualizarYTransmitir(&mapa, eventosATransmitir);
    GameLoop gameLoop(eventosAProcesar, actualizar);
    gameLoop.loop();

    /**
     * Termino el procesamiento.
     */
    auto *finProcesar = new EventoAProcesar("fin");
    eventosAProcesar->push(finProcesar);
    auto *finTransmitir = new EventoATransmitir("fin");
    eventosATransmitir->push(finTransmitir);

    pthread_join(hiloProcesamiento, nullptr);
    pthread_join(hiloTransmision, nullptr);

    return 0;
}

