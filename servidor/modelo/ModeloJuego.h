//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_MODELOJUEGO_H
#define FINAL_FIGHT_MODELOJUEGO_H


#include "../../modelo/serializables/NombrePantalla.h"
#include "../../modelo/Mapa.h"
#include "Modelo.h"

class ModeloJuego : public Modelo {

public:
    void serializar(ostream &stream) override;

};


#endif //FINAL_FIGHT_MODELOJUEGO_H
