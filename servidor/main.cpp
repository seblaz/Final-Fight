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
#include "../eventos/MostrarPantallaDeSeleccion.h"

using namespace std;

int main(int argc, char *argv[]) {
    auto *logger = new Logger();
    Locator::provide(logger);

    /**
     * Conexion al servidor.
     */
    ConexionServidor conexion(5000);
    int socketServidor = conexion.socket();

    /**
     * Conexiones de clientes.
     */
    ConexionesClientes conexiones(socketServidor, 1);
    conexiones.esperarConexiones();
    vector<int> socketsClientes = conexiones.devolverConexiones();
    pthread_t hiloRechazo = conexiones.rechazarConexionesEnHilo();

    /**
     * Procesamiento.
     */
    Procesamiento procesamiento;
    auto *eventosAProcesar = procesamiento.devolverCola();
    pthread_t hiloProcesamiento = procesamiento.procesarEnHilo();

    /**
     * Iniciar juego.
     */
    Mapa mapa;
    auto *comenzar = new MostrarPantallaDeSeleccion(&mapa);
    eventosAProcesar->push(comenzar);

    /**
     * Transmision.
     */
    Transmision transmision(socketsClientes);
    auto *eventosATransmitir = transmision.devolverCola();
    pthread_t hiloTransmision = transmision.transmitirEnHilo();

    /**
     * Contenedor de hilos.
     */
    ContenedorHilos contenedor;
    contenedor.crearHilos(socketsClientes, eventosAProcesar);
    contenedor.esperarFinDeHilos();

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