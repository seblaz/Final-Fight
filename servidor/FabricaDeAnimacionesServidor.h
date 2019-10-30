//
// Created by sebas on 20/10/19.
//

#ifndef FINAL_FIGHT_FABRICADEANIMACIONESSERVIDOR_H
#define FINAL_FIGHT_FABRICADEANIMACIONESSERVIDOR_H


#include "AnimacionServidor.h"
#include "../modelo/serializables/Personaje.h"

class FabricaDeAnimacionesServidor {

public:
    static AnimacionServidor *getAnimacion(const string& ruta);
    static AnimacionServidor *getAnimacion(enum PERSONAJE personajeSeleccionado, const string& estado);
};


#endif //FINAL_FIGHT_FABRICADEANIMACIONESSERVIDOR_H
