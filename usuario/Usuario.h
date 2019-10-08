//
// Created by leandro on 7/10/19.
//

#ifndef FINAL_FIGHT_USUARIO_H
#define FINAL_FIGHT_USUARIO_H

#include <string>
#include "../serializar/Serializable.h"

using namespace std;


class Usuario : public Serializable {
    private:
        string usuario;
        string contrasenia;

    public:
        Usuario()= default;
        virtual ~Usuario()= default;

        Usuario(string usuario, string contrasenia);
        void serializar(ostream& stream) override;
        void deserializar(istream& stream) override;
        string getUsuario();
        string getContrasenia();
};




#endif //FINAL_FIGHT_USUARIO_H
