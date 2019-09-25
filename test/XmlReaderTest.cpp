#include "gtest/gtest.h"
#include "../servicios/Configuracion.h"
#include <string>
#include <vector>

using namespace std;

TEST(XmlReader, AlPedirConfiguracionesQueExistenLasDevuelveComoString) {
    Configuracion reader = Configuracion();

    string level = reader.getValue("/debug/level");
    string fps = reader.getValue("/fps");

    EXPECT_EQ(level, "DEBUG");
    EXPECT_EQ(fps, "60");
}

TEST(XmlReader, AlPedirConfiguracionesQueNoExistenDevuelveUnaCadenaVacia) {
    Configuracion reader = Configuracion();

    string noValido = reader.getValue("/noValido/level");
    string cuchillosNoValido = reader.getValue("/escenario/objetos/cuchillo/cantidad2");

    EXPECT_EQ(noValido, "");
    EXPECT_EQ(cuchillosNoValido, "");
}