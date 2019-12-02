//
// Created by leo on 4/11/19.
//

#ifndef FINAL_FIGHT_PUNTAJE_H
#define FINAL_FIGHT_PUNTAJE_H


#include "../Entidad.h"

class Puntaje : public Estado {

private:
    int puntos = 0;

public:
    Puntaje() = default;
    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;
    void agregarPuntos(int puntos);
    int obtenerPuntos();

};


#endif //FINAL_FIGHT_PUNTAJE_H
