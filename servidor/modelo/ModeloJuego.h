//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_MODELOJUEGO_H
#define FINAL_FIGHT_MODELOJUEGO_H


#include "../../modelo/serializables/Modelo.h"
#include "../../modelo/Mapa.h"

class ModeloJuego : public Modelo {

public:
    void serializar(ostream &stream) override;
    void deserializar(istream &stream) override;

};


#endif //FINAL_FIGHT_MODELOJUEGO_H
