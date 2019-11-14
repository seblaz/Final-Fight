//
// Created by franco on 13/11/19.
//

#ifndef FINAL_FIGHT_ELIMINADO_H
#define FINAL_FIGHT_ELIMINADO_H


#include "../Entidad.h"

class Eliminado : public Estado {

private:
    bool eliminado = false;

public:
    Eliminado() = default;
    void eliminar();
    bool status();

    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;

};


#endif //FINAL_FIGHT_ELIMINADO_H
