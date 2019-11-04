//
// Created by sebas on 20/10/19.
//

#ifndef FINAL_FIGHT_ESTADODEPERSONAJE_H
#define FINAL_FIGHT_ESTADODEPERSONAJE_H


#include "../Entidad.h"

enum ESTADO_DE_PERSONAJE {
    CAMINANDO,
    SALTANDO,
    SALTANDO_CON_MOVIMIENTO,
    REPOSANDO,
    GOLPEANDO,
    AGACHADO,
    PATEANDO
};

class EstadoDePersonaje : public Estado {

private:
    ESTADO_DE_PERSONAJE estado;

public:
    static string estadoACadena(ESTADO_DE_PERSONAJE e);
    EstadoDePersonaje();
    explicit EstadoDePersonaje(ESTADO_DE_PERSONAJE);
    ESTADO_DE_PERSONAJE getEstado();

    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;
};


#endif //FINAL_FIGHT_ESTADODEPERSONAJE_H
