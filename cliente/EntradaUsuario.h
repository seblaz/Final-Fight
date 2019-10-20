//
// Created by sebas on 9/10/19.
//

#ifndef FINAL_FIGHT_ENTRADAUSUARIO_H
#define FINAL_FIGHT_ENTRADAUSUARIO_H


#include <mutex>
#include "../modelo/Accion.h"
#include "../modelo/Socket.h"
#include "../modelo/Personaje.h"
#include "../servicios/Configuracion.h"

/**
 * Lectura de input de usuario.
 */
class EntradaUsuario {

public:
    virtual Accion *getAccion() = 0;

};

class EntradaNula : public EntradaUsuario {

public:
    Accion *getAccion() override;

};

class EntradaMenuSeleccion : public EntradaUsuario {

private:
    Entidad *entidad;
    bool activo = true;
    int framesPorAccion = 20;
    int framesInactivo = 0;

public:
    Accion *getAccion() override;
    explicit EntradaMenuSeleccion(Entidad *entidad) ;
    Entidad* getEntidad() { return entidad; };
};

class EntradaJuego : public EntradaUsuario {

public:
    Accion *getAccion() override;

};

/**
 * Transmisión al servidor.
 */

class TrasmisionCliente {

private:
    std::mutex m;
    Socket socket;
    EntradaUsuario *entradaUsuario;
    bool fin = false;

    void transmitir();

    EntradaUsuario *getEntradaUsuario();

public:
    explicit TrasmisionCliente(Socket socket, EntradaUsuario *entradaUsuario);

    void setEntradaUsuario(EntradaUsuario *entradaUsuario);

    pthread_t transmitirEnHilo();

    void finalizar();
};

#endif //FINAL_FIGHT_ENTRADAUSUARIO_H
