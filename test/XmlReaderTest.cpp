#include "gtest/gtest.h"
#include "../servicios/XmlReader.h"
#include <string>
#include <vector>

using namespace std;

TEST(XmlReader, AlPedirConfiguracionesQueExistenLasDevuelveComoString) {
    XmlReader reader = XmlReader();

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
    XmlReader reader = XmlReader("/Novalido/");

    string level = reader.getValue("/debug/level");
    string cuchillos = reader.getValue("/escenario/objetos/cuchillo/cantidad");
    string noValido = reader.getValue("/noValido/level");
    string cuchillosNoValido = reader.getValue("/escenario/objetos/cuchillo/cantidad2");

    EXPECT_EQ(level, "DEBUG");
    EXPECT_EQ(cuchillos, "5");
    EXPECT_EQ(noValido, "");
    EXPECT_EQ(cuchillosNoValido, "");
}