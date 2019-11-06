//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_MODELOAUTENTICACION_H
#define FINAL_FIGHT_MODELOAUTENTICACION_H


#include <mutex>
#include "Modelo.h"

using namespace std;

enum class EVENTO_USUARIO {
    CONTRASENIA_INCORRECTA,
    USUARIO_YA_CONECTADO,
    PARTIDA_LLENA,
    NULO
};

class ModeloAutenticacion : public Modelo {

private:
    EVENTO_USUARIO evento = EVENTO_USUARIO::NULO;
    mutex m;

public:
    void partidaCompleta();
    void passwordIncorrecta();
    void usuarioYaConectado();
    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;

};


#endif //FINAL_FIGHT_MODELOAUTENTICACION_H
