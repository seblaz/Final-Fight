//
// Created by sebas on 8/10/19.
//

#ifndef FINAL_FIGHT_ACCION_H
#define FINAL_FIGHT_ACCION_H

#include "../serializar/Serializable.h"

enum ACCION {
    SELECCIONAR_SIGUIENTE,
    SELECCIONAR_ANTERIOR,
    CONFIRMAR,
    GOLPEAR,
    SALTAR
};

class Accion : public Serializable {

private:
    ACCION accion_;

public:
    Accion();
    explicit Accion(ACCION accion);
    ACCION accion();
    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;

};


#endif //FINAL_FIGHT_ACCION_H
