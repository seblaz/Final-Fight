//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_MODELOAUTENTICACION_H
#define FINAL_FIGHT_MODELOAUTENTICACION_H


#include <mutex>
#include "../../modelo/serializables/NombrePantalla.h"
#include "../../modelo/serializables/EventoUsuario.h"
#include "Modelo.h"

using namespace std;


class ModeloAutenticacion : public Modelo {

private:
    EventoUsuario evento = EventoUsuario(EVENTO_USUARIO::NULO);
    mutex m;

public:
    void partidaCompleta();
    void passwordIncorrecta();
    void usuarioYaConectado();
    void serializar(ostream& stream) override;

};


#endif //FINAL_FIGHT_MODELOAUTENTICACION_H
