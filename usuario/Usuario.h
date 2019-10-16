//
// Created by leandro on 7/10/19.
//

#ifndef FINAL_FIGHT_USUARIO_H
#define FINAL_FIGHT_USUARIO_H

#include <string>
#include "../serializar/Serializable.h"
#include "../modelo/Entidad.h"
#include "../modelo/Socket.h"
#include "../modelo/Personaje.h"

using namespace std;


class Usuario : public Serializable {

private:
    string usuario;
    string contrasenia;
    Entidad *personaje;
    Socket *socket;
    enum PERSONAJE personajeSeleccionado;

public:
    Usuario() = default;
    virtual ~Usuario() = default;
    Usuario(string usuario, string contrasenia);
    void serializar(ostream &stream) override;
    void deserializar(istream &stream) override;
    string getUsuario();
    string getContrasenia();
    void setPersonaje(Entidad *pEntidad);
    Entidad *getPersonaje();
    Socket *getSocket();
    void setSocket(Socket *socket);
    bool operator==(const Usuario &otroUsuario);
    void setPersonajeSeleccionado(enum PERSONAJE personajeSeleccionado);
    enum PERSONAJE getPersonajeSeleccionado();

};


#endif //FINAL_FIGHT_USUARIO_H
