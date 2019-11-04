//
// Created by leo on 4/11/19.
//

#ifndef FINAL_FIGHT_PUNTAJE_H
#define FINAL_FIGHT_PUNTAJE_H


#include "../Entidad.h"

class Puntaje : Estado {

private:
    int puntos;

public:
    explicit Puntaje();
    void serializar(ostream& stream) override;
    void deserializar(istream& stream) override;
    void agregarPuntos(int puntos);
    int obtenerPuntos();
};


#endif //FINAL_FIGHT_PUNTAJE_H
