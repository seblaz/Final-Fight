//
// Created by sebas on 9/10/19.
//

#ifndef FINAL_FIGHT_ENTRADAUSUARIO_H
#define FINAL_FIGHT_ENTRADAUSUARIO_H


#include <mutex>
#include "../modelo/Accion.h"
#include "../modelo/Socket.h"
#include "../modelo/Personaje.h"

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
    enum PERSONAJE personajeSeleccionado;
    bool activo = true;

public:
    Accion *getAccion() override;

    EntradaMenuSeleccion(enum PERSONAJE personajeSeleccionado_);

    enum PERSONAJE getPersonajeSeleccionado() { return personajeSeleccionado; };
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

    void transmitir();

    EntradaUsuario *getEntradaUsuario();

public:
    explicit TrasmisionCliente(Socket socket, EntradaUsuario *entradaUsuario);

    void setEntradaUsuario(EntradaUsuario *entradaUsuario);

    pthread_t transmitirEnHilo();
};

#endif //FINAL_FIGHT_ENTRADAUSUARIO_H
