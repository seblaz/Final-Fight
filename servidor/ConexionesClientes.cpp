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

ConexionesClientes::ConexionesClientes(int socketServidor, ManagerUsuarios* managerUsuarios, Mapa mapa) :
        manager(managerUsuarios),
        socketServidor(socketServidor),
        mapa(mapa){}

ConexionesClientes::~ConexionesClientes() {
    /*for(int socket : socketsClientes)
        close(socket); REVISAR VER SI CORRESPONDE EN USUARIO*/
    Locator::logger()->log(DEBUG, "Se cerraron todos los sockets hacia los clientes.");
}

void ConexionesClientes::esperarConexiones() {
    Locator::logger()->log(INFO, "Esperando " + to_string(manager->cantidadJugadoresFaltantes())+ " jugador(es).");

    while (manager->faltanJugadores()) {

        sockaddr_in newSockAddr{};
        socklen_t newSockAddrSize = sizeof(newSockAddr);

        // accept, create a new socket descriptor to handle the new connection with client
        int nuevoSocket = accept(socketServidor, (sockaddr * ) & newSockAddr, &newSockAddrSize);

        if (nuevoSocket < 0) {
            Locator::logger()->log(ERROR, "Error al aceptar el pedido de conexión del cliente.");
        } else {
            evaluarIngresoDeJugador(nuevoSocket, false, manager);
        }
    }

    Locator::logger()->log(INFO, "Se inicia el juego.");
}

void ConexionesClientes::administrarConexionesEntrantes() {
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
    /*for(int socket : socketsClientes){
        conexiones.emplace_back(socket);
    } //manager.devolverConexiones()        REVISAR*/
    return conexiones;
}

pthread_t ConexionesClientes::abrirHiloConexionesEntrantes() {
    pthread_t hilo;
    pthread_create(&hilo, nullptr, [](void* arg)->void *{
            auto *conexiones = (ConexionesClientes *)arg;
        conexiones->administrarConexionesEntrantes();
            return nullptr;
        }, (void *) this);

    Locator::logger()->log(DEBUG, "Se creó el hilo de rechazo de conexiones.");

    return hilo;
}

void ConexionesClientes::evaluarIngresoDeJugador(int nuevoSocket, bool juegoComenzado, ManagerUsuarios *pManager) {
    Socket* socketNuevoUsuario = new Socket(nuevoSocket);

    stringstream user;
    socketNuevoUsuario->recibir(user);
    Usuario nuevoUsuario;
    nuevoUsuario.deserializar(user);

    string password = Locator::configuracion()->getValue("/juego/password");

    if(password == nuevoUsuario.getContrasenia()){
        if(pManager->estaPresente(nuevoUsuario) == juegoComenzado){

            if(juegoComenzado){
                pManager->cambiarSocketParaUsuario(nuevoUsuario.getUsuario(), socketNuevoUsuario);
            }else{
                ingresarNuevoUsuario(nuevoUsuario, socketNuevoUsuario, pManager);
            }

        }else{
            Locator::logger()->log(ERROR, "Usuario " + nuevoUsuario.getUsuario() +  " no puede ingresar al juego.");
        }
    }else{
        Locator::logger()->log(ERROR, "Contraseña invalida para jugador " + nuevoUsuario.getUsuario());
    }
}

void
ConexionesClientes::ingresarNuevoUsuario(Usuario nuevoUsuario, Socket* pSocketNuevoUsuario, ManagerUsuarios* pManager) {
    Entidad* jugador = mapa.crearJugador();
    nuevoUsuario.setPersonaje(jugador);

    nuevoUsuario.setSocket(pSocketNuevoUsuario);

    try{
        pManager->agregarUsuario(nuevoUsuario); // REVISAR iniciar hilo
    }catch(...){
        Locator::logger()->log(ERROR, "No se pudo agregar el jugador al juego.");
        delete jugador;
        close(pSocketNuevoUsuario->getIntSocket());
    }

    Locator::logger()->log(INFO, "Nuevo usuario conectado. Esperando " + to_string(manager->cantidadJugadoresFaltantes()) + " jugador(es).");
}