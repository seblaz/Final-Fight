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

int main(int argc, char *argv[]) {
    auto *logger = new Logger();
    Locator::provide(logger);

    auto *config = new Configuracion();
    Locator::provide(config);

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

    managerUsuarios.esperarUsuarios();

    /**
     * Game loop.
     */
    auto *comenzar = new MostrarMenuSeleccion(&mapa);
    eventosAProcesar->push(comenzar);

    auto *actualizar = new ActualizarYTransmitir(&mapa, eventosATransmitir);
    GameLoop gameLoop(eventosAProcesar, actualizar);
    gameLoop.loop();
//    pthread_t hiloGameLoop = gameLoop.loopEnHilo();

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