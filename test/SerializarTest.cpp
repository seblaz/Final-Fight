//
// Created by sebas on 6/10/19.
//
#include <utility>

#include "gtest/gtest.h"
#include "../serializar/Serializador.h"

using namespace std;

class UnaClase : public Serializador {

private:
    int x;
    string c;
    Entidad *entidad;

public:
    UnaClase() = default;

    UnaClase(int x, string c) : x(x), c(std::move(c)) {}

    void serializar(ostream &stream) override {
        // Serialization code
        serializarEntero(stream, x);
    }

    void deserializar(istream &stream) override {
//        stream >> x;
        x = deserializarEntero(stream);
    }

    bool operator==(const UnaClase &obj) {
        return (x == obj.x) && (c == obj.c);
    }

};

//ostream &operator<<(ostream &in, const UnaClase &obj) {
//    in << 5;
//    return in << obj.x << endl << obj.c << endl;
//}
//
//std::istream &operator>>(std::istream &in, UnaClase &obj) {
//    string line;
//    getline(in, line);
//    obj.x = atoi(line.c_str());
//    getline(in, line);
//    obj.c = line;
//    return in;
//}
//

TEST(Serializar, PuedoSerializarUnaClase) {

    UnaClase unObjeto(10, "mi cadena");
    stringstream s;
    unObjeto.serializar(s);

    UnaClase otroObjeto;
//    stringstream s("10mi cadena");
    otroObjeto.deserializar(s);

    cout << (unObjeto == otroObjeto);
}