//
// Created by sebas on 14/10/19.
//

#ifndef FINAL_FIGHT_ACTIVIDAD_H
#define FINAL_FIGHT_ACTIVIDAD_H


#include "Entidad.h"

class Actividad : public Estado, public Serializable {

private:
    bool activo_ = true;

public:
    Actividad()= default;
    explicit Actividad(bool activo);
    bool estaActivo();
    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;
};


#endif //FINAL_FIGHT_ACTIVIDAD_H
