//
// Created by leo on 12/11/19.
//

#ifndef FINAL_FIGHT_ARMA_H
#define FINAL_FIGHT_ARMA_H


#include "../Entidad.h"

enum class ARMA {
    PUNIOS,
    CUCHILLO,
    TUBO
};


class Arma : public Estado {

private:
    ARMA arma;
    int danio;
    int usosRestantes;
    int puntosParaPersonaje;

public:
    static string armaACadena(ARMA arma);
    explicit Arma(ARMA arma);
    void usar();
    int getPuntosDeDanio();
    int getPuntosParaPersonaje();
    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;
    bool tieneUsosRestantes();
};

#endif //FINAL_FIGHT_ARMA_H
