//
// Created by sebas on 4/10/19.
//

#include "ConexionServidor.h"
#include "../servicios/Locator.h"
#include "ConexionesClientes.h"
#include "ContenedorHilos.h"
#include "Procesamiento.h"

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
    pthread_t p1 = conexiones.rechazarConexionesEnHilo();

    /**
     * Procesamiento.
     */
    Procesamiento procesamiento;
    auto *eventos = procesamiento.devolverCola();
    pthread_t hiloProcesamiento = procesamiento.procesarEnHilo();

    /**
     * Contenedor de hilos.
     */
    ContenedorHilos contenedor;
    contenedor.crearHilos(socketsClientes, eventos);
    contenedor.esperarFinDeHilos();

    /**
     * Termino el procesamiento.
     */
    auto *fin = new Evento("fin");
    eventos->push(fin);
    pthread_join(hiloProcesamiento, nullptr);

    return 0;
}