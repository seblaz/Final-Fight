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

    ASSERT_TRUE(posicionCliente == posicionServidor);
}

TEST(Serializar, SerializarUnaOrientacion) {

    Orientacion orientacionServidor(true);
    stringstream s;
    orientacionServidor.serializar(s);

    Orientacion orientacionCliente;
    orientacionCliente.deserializar(s);

    ASSERT_TRUE(orientacionCliente == orientacionServidor);
}

TEST(Serializar, SerializarUnTipo) {
    Tipo tipo(PANTALLA_SELECCION);
    stringstream s;
    tipo.serializar(s);

    Tipo otroTipo;
    otroTipo.deserializar(s);

    ASSERT_TRUE(tipo == otroTipo);
}

TEST(Serializar, SerializarUnaEntidad) {
    Entidad entidad;
    Tipo tipo(JUGADOR);
    Posicion posicion(10, 42, 12);
    entidad.agregarEstado("tipo", &tipo);
    entidad.agregarEstado("posicion", &posicion);

    stringstream s;
    entidad.serializar(s);

    Entidad otraEntidad;
    otraEntidad.deserializar(s);

    bool eq1 = *entidad.getEstado<Posicion>("posicion") == *otraEntidad.getEstado<Posicion>("posicion");
    bool eq2 = *entidad.getEstado<Tipo>("tipo") == *otraEntidad.getEstado<Tipo>("tipo");
    ASSERT_TRUE(eq1 && eq2);
}

TEST(Serializar, SerializarVariasEntidades) {
    Entidad entidad1;
    Tipo tipo1(JUGADOR);
    Posicion posicion1(10, 42, 12);
    entidad1.agregarEstado("tipo", &tipo1);
    entidad1.agregarEstado("posicion", &posicion1);

    Entidad entidad2;
    Tipo tipo2(PANTALLA_SELECCION);
    Orientacion orientacion2(true);
    entidad2.agregarEstado("tipo", &tipo2);
    entidad2.agregarEstado("orientacion", &orientacion2);

    stringstream s;
    entidad1.serializar(s);
    entidad2.serializar(s);

    Entidad otraEntidad1;
    Entidad otraEntidad2;
    otraEntidad1.deserializar(s);
    otraEntidad2.deserializar(s);

    bool eq1 = *entidad1.getEstado<Posicion>("posicion") == *otraEntidad1.getEstado<Posicion>("posicion");
    bool eq2 = *entidad1.getEstado<Tipo>("tipo") == *otraEntidad1.getEstado<Tipo>("tipo");

    bool eq3 = *entidad2.getEstado<Orientacion>("orientacion") == *otraEntidad2.getEstado<Orientacion>("orientacion");
    bool eq4 = *entidad2.getEstado<Tipo>("tipo") == *otraEntidad2.getEstado<Tipo>("tipo");
    ASSERT_TRUE(eq1 && eq2 && eq3 && eq4);
}