//
// Created by sebas on 4/10/19.
//

#include <iostream>
#include <string>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include "ConexionCliente.h"
#include "../servicios/Locator.h"
#include "Entrada.h"
#include "../main/Juego.h"
#include "../niveles/Nivel.h"

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

        ConexionCliente conexion(ipAddress, port);
        int socket = conexion.socket();
        Locator::provide(socket);

        Juego juego;
        SDL_Renderer *renderer = juego.renderer();
        Locator::provide(renderer);
        Mapa &mapa = juego.mapa();
        Nivel::generarPantallaDeEspera(&mapa);

        Entrada entrada(socket);
        entrada.procesarEntradaEnHilo();

        juego.loop();
        juego.terminar();
    }
}