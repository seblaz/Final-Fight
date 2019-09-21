//
// Created by sebas on 2/9/19.
//

#ifndef FINAL_FIGHT_ICOMPORTAMIENTO_H
#define FINAL_FIGHT_ICOMPORTAMIENTO_H


#include "../modelo/mapeables/Mapeable.h"
#include "../graficos/Animacion.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"
#include "../graficos/FabricaDeAnimacionesDePoison.h"


class IComportamiento {

public:
    virtual void actualizar() = 0;
    virtual Animacion* devolverAnimacion(){};
};


#endif //FINAL_FIGHT_ICOMPORTAMIENTO_H
