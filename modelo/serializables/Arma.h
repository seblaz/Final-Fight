//
// Created by leo on 12/11/19.
//

#ifndef FINAL_FIGHT_ARMA_H
#define FINAL_FIGHT_ARMA_H


#include "../Entidad.h"

enum class TIPO_ARMA {
    ArmaPunios = 1,
    Cuchillo = 2,
    Tubo = 3
};


class Arma : public Estado {
    protected:
        int usosPendientes;
        int puntosParaPersonaje;
        int puntosDeDanio;
        TIPO_ARMA tipoArma;

    public:
        int getPuntosParaPersonaje();
        int getPuntosDeDanio();
        void restarUso();
        void serializar(ostream& stream) override;
        void deserializar(istream& stream) override;
};

class ArmaPunios : public Arma {
    public:
        ArmaPunios();
};

class Cuchillo : public Arma {
    public:
        Cuchillo();
};

class Tubo : public Arma {
    public:
        Tubo();
};


#endif //FINAL_FIGHT_ARMA_H
