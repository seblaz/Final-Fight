//
// Created by franco on 13/10/19.
//

#ifndef FINAL_FIGHT_TIPOELEMENTO_H
#define FINAL_FIGHT_TIPOELEMENTO_H

#include "Entidad.h"

enum elementos{
    CAJA,
    NEUMATICO,
    TUBO,
    CUCHILLO
};


class TipoElemento : public Estado {

private:
    int elemento{};

public:
    TipoElemento() = default;
    explicit TipoElemento(int art);
    int getElemento();

    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;

};


#endif //FINAL_FIGHT_TIPOELEMENTO_H
