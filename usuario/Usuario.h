//
// Created by leandro on 7/10/19.
//

#ifndef FINAL_FIGHT_USUARIO_H
#define FINAL_FIGHT_USUARIO_H

#include <string>
#include "../modelo/serializables/Serializable.h"
#include "../modelo/Entidad.h"
#include "../modelo/Socket.h"
#include "../modelo/serializables/Personaje.h"

using namespace std;


class Usuario : private Serializable {

private:
    string usuario;
    string contrasenia;
    Entidad *personaje{};
    enum PERSONAJE personajeSeleccionado = CODY;
    bool valido_{};
    bool conectado = true;
    bool desconectadoVoluntariamente = false;
//    Socket *socket{};

public:
    Usuario() = default;
    ~Usuario() override = default;
    Usuario(string usuario, string contrasenia);

    string getUsuario();
    string getContrasenia();

    void setPersonaje(Entidad *personaje);
    Entidad *getPersonaje();

//    void setSocket(Socket *socket);
//    Socket *getSocket();

    bool estaConectado();
    void desconectar();

    void desconectarVoluntariamente();
    bool estaDesconectadoVoluntariamente();

    void setValido(bool valido);
    bool getValido();

    bool operator==(const Usuario &otroUsuario);
    void serializar(ostream &stream) override;
    void deserializar(istream &stream) override;

    void setPersonajeSeleccionado(enum PERSONAJE personajeSeleccionado);
    enum PERSONAJE getPersonajeSeleccionado();

};


#endif //FINAL_FIGHT_USUARIO_H
