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

void configApplication(int argc, char *argv[]){
    string configPath;
    string nivelDebug;

    if(argc > 3){
        if(argc == 4){
            string param = argv[3];
            size_t found = param.find(".xml");


            if(found==std::string::npos){
                nivelDebug = param;
            }else{
                configPath = param;
            }
        }else{
            nivelDebug = argv[3];
            configPath = argv[4];
        }
    }

    auto *config = configPath.empty() ? new Configuracion() : new Configuracion(configPath);
    Locator::provide(config);

    if(nivelDebug.empty()){
        string loggerLevel = config->getValue("/debug/level");
        if(!loggerLevel.empty()){
            Locator::logger()->setLevel(loggerLevel);
        }
    }else{
        Locator::logger()->setLevel(nivelDebug);
    }
}

//Client side
int main(int argc, char *argv[]) {
    auto *logger = new Logger();
    Locator::provide(logger);

    string ipAddress;
    int port;
    bool paramsOk = false;

    if (argc < 3) {
        logger->log(ERROR, "No se recibio ip y/o puerto. Se termina la ejecucion");
    } else {
        ipAddress = argv[1];

        try {
            port = stoi(argv[2]);
            paramsOk = true;
        } catch (...) {
            logger->log(ERROR, "Error en puerto recibido. Se termina la ejecucion.");
        }
    }

    if (paramsOk) {
        configApplication(argc, argv);


        /**
         * Conexion cliente.
         */
        ConexionCliente conexion(ipAddress, port);
        Socket socket = conexion.socket();
        Locator::provide(socket);

        /**
         * Iniciar juego.
         */
        Juego juego;
        SDL_Renderer *renderer = juego.renderer();
        Locator::provide(renderer);
        Mapa &mapa = juego.mapa();
        NivelCliente::generarPantallaDeEspera(&mapa);

        juego.loop();
        juego.terminar();

    }

    return 0;

}