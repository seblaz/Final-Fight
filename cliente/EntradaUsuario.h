//
// Created by sebas on 9/10/19.
//

#ifndef FINAL_FIGHT_ENTRADAUSUARIO_H
#define FINAL_FIGHT_ENTRADAUSUARIO_H


#include "../modelo/Accion.h"

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

public:
    Accion *getAccion() override;

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
    int socket;
    EntradaUsuario *entradaUsuario;
    void transmitir();

public:
    explicit TrasmisionCliente(int socket, EntradaUsuario *entradaUsuario);
    pthread_t transmitirEnHilo();
    void setEntradaUsuario(EntradaUsuario *entradaUsuario);
};

#endif //FINAL_FIGHT_ENTRADAUSUARIO_H
