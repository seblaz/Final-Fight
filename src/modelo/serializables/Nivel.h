//
// Created by sebas on 9/10/19.
//

#ifndef FINAL_FIGHT_NIVEL_H
#define FINAL_FIGHT_NIVEL_H


#include "../Entidad.h"

class Nivel : public Estado {

private:
    string nivel_;

public:
    Nivel();
    explicit Nivel(string nivel);

    string nivel();

    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;
};


#endif //FINAL_FIGHT_NIVEL_H
