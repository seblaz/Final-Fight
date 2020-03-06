//
// Created by sebas on 6/10/19.
//

#ifndef FINAL_FIGHT_SERIALIZABLE_H
#define FINAL_FIGHT_SERIALIZABLE_H


//#include "../modelo/Mapa.h"
#include <sstream>

using namespace std;

class Serializable {

public:
    Serializable() = default;
    virtual ~Serializable() = default;

    virtual void serializar(ostream& stream) = 0;
    virtual void deserializar(istream& stream) = 0;

protected:
    static void serializarEntero(ostream& stream, int entero);
    static int deserializarEntero(istream& stream);

    static void serializarString(ostream& stream, const string& string);
    static string deserializarString(istream& stream);

    static void serializarBoolean(ostream& stream, bool boolean);
    static bool deserializarBoolean(istream& stream);

};


#endif //FINAL_FIGHT_SERIALIZABLE_H
