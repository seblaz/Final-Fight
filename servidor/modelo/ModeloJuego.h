//
// Created by sebas on 5/11/19.
//

#ifndef FINAL_FIGHT_MODELOJUEGO_H
#define FINAL_FIGHT_MODELOJUEGO_H


#include "Modelo.h"
#include "../../modelo/Mapa.h"

class ModeloJuego : Modelo {

private:
    Mapa *mapa;

public:
    explicit ModeloJuego(Mapa *mapa);
    void serializar(ostream &stream) override;
    void deserializar(istream &stream) override;

};


#endif //FINAL_FIGHT_MODELOJUEGO_H
