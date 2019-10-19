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

public:
    Accion *getAccion() override;

    EntradaMenuSeleccion(Entidad *entidad) ;

    Entidad* getEntidad() { return entidad; };

    void cambiarSpriteAlAnterior(enum PERSONAJE personajeMarcado) const;

    void cambiarAlSpriteSiguiente(enum PERSONAJE personajeMarcado) const;
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
