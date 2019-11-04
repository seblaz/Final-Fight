//
// Created by sebas on 2/11/19.
//

#ifndef FINAL_FIGHT_FABRICADEANIMACIONESCLIENTE_H
#define FINAL_FIGHT_FABRICADEANIMACIONESCLIENTE_H

#include <string>
#include "AnimacionCliente.h"
#include "../modelo/serializables/EstadoDePersonaje.h"

using namespace std;

class FabricaDeAnimacionesCliente : public Estado {

private:
    string rutaBase;
    unordered_map<string, AnimacionCliente *> animaciones;

public:
    explicit FabricaDeAnimacionesCliente(string rutaBase);
    AnimacionCliente *getAnimacion(const string& rutaFinal);
    AnimacionCliente *getAnimacion(ESTADO_DE_PERSONAJE estado);

};


#endif //FINAL_FIGHT_FABRICADEANIMACIONESCLIENTE_H
