//
// Created by sebas on 9/10/19.
//

#ifndef FINAL_FIGHT_ENTRADAUSUARIO_H
#define FINAL_FIGHT_ENTRADAUSUARIO_H


#include <mutex>
#include <SDL_events.h>
#include "../../modelo/serializables/Accion.h"
#include "../../modelo/Socket.h"
#include "../../modelo/serializables/Personaje.h"
#include "../../servicios/Configuracion.h"

/**
 * Lectura de input de usuario.
 */
class EntradaUsuario {

public:
    virtual Accion *getAccion(SDL_Event *e) = 0;

};

class EntradaNula : public EntradaUsuario {

public:
    Accion *getAccion(SDL_Event *e) override;

};

//class EntradaMenuSeleccion : public EntradaUsuario {
//
//private:
//    Entidad *pantalla;
//    bool activo = true;
//    int framesPorAccion = 20;
//    int framesInactivo = 20;
//    static void cambiarAlPersonajeAnterior(Personaje *personajeMarcado);
//    static void cambiarAlPersonajeSiguiente(Personaje *personajeMarcado);
//
//public:
//    Accion *getAccion(SDL_Event *e) override;
//    explicit EntradaMenuSeleccion(Entidad *entidad) ;
//};

class EntradaJuego : public EntradaUsuario {

public:
    Accion *getAccion(SDL_Event *e) override;

};

/**
 * Transmisión al servidor.
 */

//class TrasmisionCliente {
//
//private:
//    std::mutex m;
//    Socket *socket;
//    EntradaUsuario *entradaUsuario;
//    bool fin = false;
//
//    void transmitir();
//
//    EntradaUsuario *getEntradaUsuario();
//
//public:
//    explicit TrasmisionCliente(Socket *socket, EntradaUsuario *entradaUsuario);
//
//    void setEntradaUsuario(EntradaUsuario *entradaUsuario);
//
//    pthread_t transmitirEnHilo();
//
//    void finalizar();
//};

#endif //FINAL_FIGHT_ENTRADAUSUARIO_H
