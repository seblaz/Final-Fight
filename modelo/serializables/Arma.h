//
// Created by leo on 12/11/19.
//

#ifndef FINAL_FIGHT_ARMA_H
#define FINAL_FIGHT_ARMA_H


#include "../Entidad.h"

class Arma : public Estado {
    private:
        int usosPendientes = -1;
        int puntosParaPersonaje = 100;
        int puntosDeDanio = 20;

    public:
        int getPuntosParaPersonaje();
        int getPuntosDeDanio();
        void restarUso();
};


#endif //FINAL_FIGHT_ARMA_H
