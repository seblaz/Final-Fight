//
// Created by sebas on 6/10/19.
//
#include <utility>

#include "gtest/gtest.h"
#include "../serializar/Serializador.h"
#include "../modelo/Posicion.h"
#include "../modelo/Orientacion.h"

using namespace std;

class UnaClase : public Serializador {

private:
    int x;
    string c;
    bool b;
    Entidad *entidad;

public:
    UnaClase() = default;

    UnaClase(int x, string c, bool b) : x(x), c(std::move(c)), b(b) {}

    void serializar(ostream &stream) override {
        // Serialization code
        serializarEntero(stream, x);
        serializarString(stream, c);
        serializarBoolean(stream, b);
    }

    void deserializar(istream &stream) override {
//        stream >> x;
        x = deserializarEntero(stream);
        c = deserializarString(stream);
        b = deserializarBoolean(stream);
    }

    bool operator==(const UnaClase &obj) {
        return (x == obj.x) && (c == obj.c) && ( b == obj.b );
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

    UnaClase unObjeto(10, "mi cadena", true);
    stringstream s;
    unObjeto.serializar(s);

    UnaClase otroObjeto;
//    stringstream s("10mi cadena");
    otroObjeto.deserializar(s);

    cout << (unObjeto == otroObjeto);
}

TEST(SerializarPosicion, SerializarUnaPosicion) {

    Posicion posicionServidor(10, 10, 10);
    stringstream s;
    posicionServidor.serializar(s);

    Posicion posicionCliente;
    posicionCliente.deserializar(s);

    cout << (posicionCliente.x == posicionServidor.x && posicionCliente.y == posicionServidor.y && posicionCliente.z == posicionServidor.z);
}

TEST(SerializarOrientacion, SerializarUnaOrientacion) {

    Orientacion orientacionServidor(true);
    stringstream s;
    orientacionServidor.serializar(s);

    Orientacion orientacionCliente;
    orientacionCliente.deserializar(s);

    cout << ( orientacionCliente.adelante == orientacionServidor.adelante );
}

