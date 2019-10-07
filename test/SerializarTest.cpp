//
// Created by sebas on 6/10/19.
//
#include <utility>

#include "gtest/gtest.h"
#include "../serializar/Serializable.h"
#include "../modelo/Posicion.h"
#include "../modelo/Orientacion.h"

using namespace std;

class UnaClase : public Serializable {

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
        x = deserializarEntero(stream);
        c = deserializarString(stream);
        b = deserializarBoolean(stream);
    }

    bool operator==(const UnaClase &obj) {
        return (x == obj.x) && (c == obj.c) && ( b == obj.b );
    }

};

TEST(Serializar, PuedoSerializarUnaClase) {

    UnaClase unObjeto(10, "mi cadena", true);
    stringstream s;
    unObjeto.serializar(s);

    UnaClase otroObjeto;
    otroObjeto.deserializar(s);

    ASSERT_TRUE(unObjeto == otroObjeto);
}

TEST(Serializar, SerializarUnaPosicion) {

    Posicion posicionServidor(10, 10, 10);
    stringstream s;
    posicionServidor.serializar(s);

    Posicion posicionCliente;
    posicionCliente.deserializar(s);

    ASSERT_TRUE(posicionCliente.x == posicionServidor.x && posicionCliente.y == posicionServidor.y && posicionCliente.z == posicionServidor.z);
}

TEST(Serializar, SerializarUnaOrientacion) {

    Orientacion orientacionServidor(true);
    stringstream s;
    orientacionServidor.serializar(s);

    Orientacion orientacionCliente;
    orientacionCliente.deserializar(s);

    ASSERT_TRUE( orientacionCliente.adelante == orientacionServidor.adelante );
}

TEST(Serializar, SerializarUnTipo) {
    Tipo tipo(PANTALLA_SELECCION);
    stringstream s;
    tipo.serializar(s);

    Tipo otroTipo;
    otroTipo.deserializar(s);

    ASSERT_TRUE(tipo == otroTipo);
}

