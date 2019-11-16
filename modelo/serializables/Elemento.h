//
// Created by franco on 13/10/19.
//

#ifndef FINAL_FIGHT_ELEMENTO_H
#define FINAL_FIGHT_ELEMENTO_H

#include "../Entidad.h"

enum class ELEMENTO{
    CAJA,
    BARRIL
};


class Elemento : public Estado {

private:
    ELEMENTO elemento;
    int golpes;

public:
    Elemento();
    Elemento(ELEMENTO elemento);

    ELEMENTO getElemento();
    void recibirGolpeDe(Entidad* golpeador);
    bool estaRoto();

    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;

    static string ElementoACadena(ELEMENTO elemento);

};


#endif //FINAL_FIGHT_ELEMENTO_H
