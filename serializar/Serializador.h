//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_SERIALIZADOR_H
#define FINAL_FIGHT_SERIALIZADOR_H


#include "../modelo/Mapa.h"

using namespace std;

class Serializador {

public:
    Serializador()= default;
    virtual ~Serializador()= default;

    virtual void serializar(ostream& stream) = 0;
    virtual void deserializar(istream& stream) = 0;

    static void serializarEntero(ostream& stream, int entero);
    static int deserializarEntero(istream& stream);

};


#endif //FINAL_FIGHT_SERIALIZADOR_H
