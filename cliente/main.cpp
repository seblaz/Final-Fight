//
// Created by sebas on 4/10/19.
//

#include <string>
#include "ConexionCliente.h"
#include "../servicios/Locator.h"
#include "../main/Juego.h"
#include "ReceptorCliente.h"
#include "ActualizadorCliente.h"
#include "NivelCliente.h"
#include "EntradaUsuario.h"
#include "../usuario/Usuario.h"

using namespace std;

//Client side
int main(int argc, char *argv[]) {
    auto *logger = new Logger();
    Locator::provide(logger);
    auto* config = new Configuracion();
    Locator::provide(config);

    string ipAddress;
    int port;
    bool paramsOk = false;

    if (argc < 3){
        logger->log(ERROR, "No se recibio ip y/o puerto. Se termina la ejecucion");
    }else{
        ipAddress = argv[1];

        try{
            port = stoi(argv[2]);
            paramsOk = true;
        }catch(...){
            logger->log(ERROR, "Error en puerto recibido. Se termina la ejecucion.");
        }
    }

    if (paramsOk) {
        string user;
        string pass;


        cout << "Ingrese nombre de usuario" << endl;
        cin >> user;
        cout << "Ingrese contraseña" << endl;
        cin >> pass;

        /**
         * Conexion cliente.
         */
        ConexionCliente conexion(ipAddress, port);
        Socket socket = conexion.socket();
        Locator::provide(socket);

        Usuario usuario(user, pass);

        stringstream userStream;
        usuario.serializar(userStream);
        socket.enviar(userStream);

        /**
         * Transmisión de acciones.
         */
        EntradaNula entrada;
        TrasmisionCliente trasmision(socket, &entrada);
        trasmision.transmitirEnHilo();

        /**
         * Iniciar juego.
         */
        Juego juego;
        SDL_Renderer *renderer = juego.renderer();
        Locator::provide(renderer);
        Mapa &mapa = juego.mapa();
        NivelCliente::generarPantallaDeEspera(&mapa);

        juego.loop(&trasmision);
        juego.terminar();
    }

//    /**
//     * Actualizador.
//     */
//     ActualizadorCliente actualizador(&mapa);
//
//    /**
//     * Escuchar al servidor.
//     */
//    Escucha escucha(socket, &actualizador);
//    escucha.escucharEnHilo();

    return 0;

}