//
// Created by leandro on 7/10/19.
//

#ifndef FINAL_FIGHT_USUARIO_H
#define FINAL_FIGHT_USUARIO_H

#include <string>
#include "../serializar/Serializador.h"

using namespace std;


class Usuario : public Serializador {
    private:
        string usuario;
        string contrasenia;

    public:
        Usuario(string usuario, string contrasenia);
        void serializar(ostream& stream) override;
        void deserializar(istream& stream) override;
};




#endif //FINAL_FIGHT_USUARIO_H
