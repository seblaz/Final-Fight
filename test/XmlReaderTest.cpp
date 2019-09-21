#include "gtest/gtest.h"
#include "../servicios/Configuracion.h"
#include <string>
#include <vector>

using namespace std;

TEST(XmlReader, AlPedirConfiguracionesQueExistenLasDevuelveComoString) {
    Configuracion reader = Configuracion();

    string level = reader.getValue("/debug/level");
    string cuchillos = reader.getValue("/escenario/objetos/cuchillo/cantidad");
    string noValido = reader.getValue("/noValido/level");
    string cuchillosNoValido = reader.getValue("/escenario/objetos/cuchillo/cantidad2");

    EXPECT_EQ(level, "DEBUG");
    EXPECT_EQ(cuchillos, "5");
    EXPECT_EQ(noValido, "");
    EXPECT_EQ(cuchillosNoValido, "");
}

TEST(XmlReader, PediConfiguracionesPathNoValido) {
    Configuracion reader = Configuracion("/Novalido/");

    string level = reader.getValue("/debug/level");
    string cuchillos = reader.getValue("/escenario/objetos/cuchillo/cantidad");

    EXPECT_EQ(level, "DEBUG");
    EXPECT_EQ(cuchillos, "5");
}

TEST(XmlReader, AlPedirConfiguracionesQueNoExistenDevuelveUnaCadenaVacia) {
    Configuracion reader = Configuracion("s");

    string noValido = reader.getValue("/noValido/level");
    string cuchillosNoValido = reader.getValue("/escenario/objetos/cuchillo/cantidad2");

    EXPECT_EQ(noValido, "");
    EXPECT_EQ(cuchillosNoValido, "");
}