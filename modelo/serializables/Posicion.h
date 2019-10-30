//
// Created by sebas on 30/8/19.
//

#ifndef FINAL_FIGHT_POSICION_H
#define FINAL_FIGHT_POSICION_H


#include "../Velocidad.h"
#include "../Entidad.h"

class Posicion : public Estado {

private:

public:
    explicit Posicion(int x = 0, int y = 0, int z = 0);
    Posicion operator-(const Posicion& otraPosicion);
    void mover(Velocidad& velocidad);
    int x, y, z;
    int getX();
    int getY();
    int getZ();
    void setX(int x);

    bool operator==(const Posicion &otraPosicion);
    bool operator<(const Posicion &otraPosicion);
    int distanciaEntrePuntos(Posicion *otraPosicion);
    float modulo();
    Posicion menos(Posicion *);

    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;
};


#endif //FINAL_FIGHT_POSICION_H
