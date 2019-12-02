//
// Created by sebas on 14/10/19.
//

#ifndef FINAL_FIGHT_ACTIVIDAD_H
#define FINAL_FIGHT_ACTIVIDAD_H


#include "../Entidad.h"

class Actividad : public Estado {

private:

public:
    Actividad()= default;
    bool activo = true;
    explicit Actividad(bool activo);
    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;
};


#endif //FINAL_FIGHT_ACTIVIDAD_H
