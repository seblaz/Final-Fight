//
// Created by leo on 12/11/19.
//

#ifndef FINAL_FIGHT_ARMA_H
#define FINAL_FIGHT_ARMA_H


#include "../Entidad.h"

enum class ARMA {
    TUBO,
    CUCHILLO,
    PUNIOS,
    PATADA
};


class Arma : public Estado {

private:
    ARMA arma;
    int danio;
    int usosRestantes;
    int ancho;
    bool enSuelo = true;
    bool enUso = false;
    void inicializar(ARMA arma);

public:
    Arma();
    explicit Arma(ARMA arma);
    ARMA getArma();

    void inicioUso();
    void finUso();
    void tomar();
    int getAncho();
    bool enElSuelo();
    int getPuntosDeDanio();
    void cambiarPor(ARMA arma);

    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;

    static string armaACadena(ARMA arma);

};

#endif //FINAL_FIGHT_ARMA_H
