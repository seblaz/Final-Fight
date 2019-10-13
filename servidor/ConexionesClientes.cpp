//
// Created by sebas on 5/10/19.
//

#include "ConexionesClientes.h"
#include "../servicios/Locator.h"
#include "ReceptorServidor.h"
#include <string>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

ConexionesClientes::ConexionesClientes(int socketServidor, ListaSockets *sockets, ManagerUsuarios *managerUsuarios, ContenedorHilos* contenedor) :
        sockets(sockets),
        manager(managerUsuarios),
        socketServidor(socketServidor),
        contenedor(contenedor) {}

ConexionesClientes::~ConexionesClientes() {
    /* TODO: for(int socket : socketsClientes)
        close(socket); REVISAR VER SI CORRESPONDE EN USUARIO*/
    Locator::logger()->log(DEBUG, "Se cerraron todos los sockets hacia los clientes.");
}

void ConexionesClientes::manejarConexiones() {
    while (true) {
        sockaddr_in newSockAddr{};
        socklen_t newSockAddrSize = sizeof(newSockAddr);
        int nuevoSocket = accept(socketServidor, (sockaddr *) &newSockAddr, &newSockAddrSize);
        Socket socket(nuevoSocket);
        sockets->agregar(socket);

        if (nuevoSocket < 0) {
            Locator::logger()->log(ERROR, "Error al aceptar el pedido de conexión del cliente.");
        } else {
            contenedor->crearHilo(socket);
        }
    }
}


pthread_t ConexionesClientes::manejarConexionesEnHilo() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
        auto *conexiones = (ConexionesClientes *) arg;
        conexiones->manejarConexiones();
        return nullptr;
    }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de manejo de conexiones.");
    return hilo;
}


/**
 * Evaluar uso.
 */
//void ConexionesClientes::administrarConexionesEntrantes() {
//    sockaddr_in newSockAddr{};
//    socklen_t newSockAddrSize = sizeof(newSockAddr);
//
//    while (true) {
//        int nuevoSocket = accept(socketServidor, (sockaddr *) &newSockAddr, &newSockAddrSize);
//
//        if (nuevoSocket < 0) {
//            Locator::logger()->log(ERROR, "Error al aceptar el pedido de conexión del cliente.");
//            break;
//        } else {
//
//            Locator::logger()->log(INFO,
//                                   "Se conecta un nuevo cliente, pero la partida ya comenzó así que se termina la conexión.");
//            string msg("Juego completo");
//            send(nuevoSocket, msg.c_str(), msg.length(), 0);
//            close(nuevoSocket);
//        }
//    }
//}
//
//vector<Socket> ConexionesClientes::devolverConexiones() {
//    vector<Socket> conexiones;
//    /*for(int socket : socketsClientes){
//        conexiones.emplace_back(socket);
//    } //manager.devolverConexiones()        REVISAR*/
//    return conexiones;
//}
//
//pthread_t ConexionesClientes::abrirHiloConexionesEntrantes() {
//    pthread_t hilo;
//    pthread_create(&hilo, nullptr, [](void *arg) -> void * {
//        auto *conexiones = (ConexionesClientes *) arg;
//        conexiones->administrarConexionesEntrantes();
//        return nullptr;
//    }, (void *) this);
//
//    Locator::logger()->log(DEBUG, "Se creó el hilo de rechazo de conexiones.");
//
//    return hilo;
//}
//
//void ConexionesClientes::evaluarIngresoDeJugador(int nuevoSocket, bool juegoComenzado, ManagerUsuarios *pManager) {
//    Socket *socketNuevoUsuario = new Socket(nuevoSocket);
//
//    stringstream user;
//    socketNuevoUsuario->recibir(user);
//    Usuario nuevoUsuario;
//    nuevoUsuario.deserializar(user);
//
//    string password = Locator::configuracion()->getValue("/juego/password");
//
//    if (password == nuevoUsuario.getContrasenia()) {
//        if (pManager->estaPresente(nuevoUsuario) == juegoComenzado) {
//
//            if (juegoComenzado) {
//                pManager->cambiarSocketParaUsuario(nuevoUsuario, socketNuevoUsuario);
//            } else {
//                ingresarNuevoUsuario(nuevoUsuario, socketNuevoUsuario, pManager);
//            }
//
//        } else {
//            Locator::logger()->log(ERROR, "Usuario " + nuevoUsuario.getUsuario() + " no puede ingresar al juego.");
//        }
//    } else {
//        Locator::logger()->log(ERROR, "Contraseña invalida para jugador " + nuevoUsuario.getUsuario());
//    }
//}
//
//void
//ConexionesClientes::ingresarNuevoUsuario(Usuario nuevoUsuario, Socket *pSocketNuevoUsuario, ManagerUsuarios *pManager) {
//    Entidad *jugador = mapa->crearJugador();
//    Tipo *tipo = new Tipo(USUARIO);
//    jugador->agregarEstado("tipo", tipo);
//    Posicion *posicion = new Posicion(0, 0, 0);
//    jugador->agregarEstado("posicion", posicion);
//    nuevoUsuario.setPersonaje(jugador);
//    nuevoUsuario.setSocket(pSocketNuevoUsuario);
//
//    try {
//        pManager->agregarUsuario(nuevoUsuario); // REVISAR iniciar hilo
//    } catch (...) {
//        Locator::logger()->log(ERROR, "No se pudo agregar el jugador al juego.");
//        delete jugador;
//        close(pSocketNuevoUsuario->getIntSocket());
//    }
//
//    Locator::logger()->log(INFO,
//                           "Nuevo usuario conectado. Esperando " + to_string(manager->cantidadJugadoresFaltantes()) +
//                           " jugador(es).");
//}
