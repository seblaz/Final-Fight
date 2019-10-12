//
// Created by leandro on 7/10/19.
//

#ifndef FINAL_FIGHT_USUARIO_H
#define FINAL_FIGHT_USUARIO_H

#include <string>
#include "../serializar/Serializable.h"
#include "../modelo/Entidad.h"
#include "../modelo/Socket.h"

using namespace std;


class Usuario : public Serializable {
    private:
        string usuario;
        string contrasenia;
        Entidad* personaje;
        Socket* socket;

    public:
        Usuario()= default;
        virtual ~Usuario()= default;

        Usuario(string usuario, string contrasenia);
        void serializar(ostream& stream) override;
        void deserializar(istream& stream) override;
        string getUsuario();
        string getContrasenia();
        Socket* getSocket();

    void setPersonaje(Entidad *pEntidad);

    void setSocket(Socket* socket);
};




#endif //FINAL_FIGHT_USUARIO_H
