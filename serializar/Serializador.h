//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_SERIALIZADOR_H
#define FINAL_FIGHT_SERIALIZADOR_H


//#include "../modelo/Mapa.h"
#include <sstream>

using namespace std;

class Serializador {

public:
    Serializador()= default;
    virtual ~Serializador()= default;

    virtual void serializar(ostream& stream) = 0;
    virtual void deserializar(istream& stream) = 0;

    static void serializarEntero(ostream& stream, int entero);
    static int deserializarEntero(istream& stream);

    static void serializarString(ostream& stream, string string);
    static string deserializarString(istream& stream);

    static void serializarBoolean(ostream& stream, bool boolean);
    static bool deserializarBoolean(istream& stream);
};


#endif //FINAL_FIGHT_SERIALIZADOR_H
