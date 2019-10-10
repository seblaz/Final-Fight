//
// Created by sebas on 5/10/19.
//

#include "ConexionesClientes.h"
#include "../servicios/Locator.h"
#include "Escucha.h"
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

ConexionesClientes::ConexionesClientes(int socketServidor, ManagerUsuarios managerUsuarios) :
        jugadoresMax(jugadoresMax),
        manager(managerUsuarios),
        socketServidor(socketServidor) {}

ConexionesClientes::~ConexionesClientes() {
    for(int socket : socketsClientes)
        close(socket);
    Locator::logger()->log(DEBUG, "Se cerraron todos los sockets hacia los clientes.");
}

void ConexionesClientes::esperarConexiones() {
    Locator::logger()->log(INFO, "Esperando " + to_string(jugadoresMax)+ " jugador(es).");

    while (manager.faltanJugadores()) {

        sockaddr_in newSockAddr{};
        socklen_t newSockAddrSize = sizeof(newSockAddr);

        // accept, create a new socket descriptor to handle the new connection with client
        int nuevoSocket = accept(socketServidor, (sockaddr * ) & newSockAddr, &newSockAddrSize);



        if (nuevoSocket < 0) {
            Locator::logger()->log(ERROR, "Error al aceptar el pedido de conexión del cliente.");
        } else {
            //jugadoresFaltantes--;

            Socket socketNuevoUsuario(nuevoSocket);

            stringstream user;
            socketNuevoUsuario.recibir(user);
            Usuario nuevoUsuario;
            nuevoUsuario.deserializar(user);

            if(!manager.estaPresente(nuevoUsuario.getUsuario())){
                manager.agregarUsuario(nuevoUsuario);
                socketsClientes.push_back(nuevoSocket);
                Locator::logger()->log(INFO, "Nuevo cliente conectado. Esperando " + to_string(manager.cantidadJugadoresFaltantes()) + " jugador(es).");
            }
        }

    }
    Locator::logger()->log(INFO, "Se inicia el juego.");
}

void ConexionesClientes::rechazarProximasConexiones() {
    sockaddr_in newSockAddr{};
    socklen_t newSockAddrSize = sizeof(newSockAddr);

    while (true){
        int nuevoSocket = accept(socketServidor, (sockaddr * ) & newSockAddr, &newSockAddrSize);

        if (nuevoSocket < 0) {
            Locator::logger()->log(ERROR, "Error al aceptar el pedido de conexión del cliente.");
            break;
        } else {
            Locator::logger()->log(INFO, "Se conecta un nuevo cliente, pero la partida ya comenzó así que se termina la conexión.");
            string msg("Juego completo");
            send(nuevoSocket, msg.c_str(), msg.length(), 0);
            close(nuevoSocket);
        }
    }
}

vector<Socket> ConexionesClientes::devolverConexiones() {
    vector<Socket> conexiones;
    for(int socket : socketsClientes){
        conexiones.emplace_back(socket);
    }
    return conexiones;
}

pthread_t ConexionesClientes::rechazarConexionesEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void* arg)->void *{
            auto *conexiones = (ConexionesClientes *)arg;
            conexiones->rechazarProximasConexiones();
            return nullptr;
        }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de rechazo de conexiones.");

    return hilo;
}