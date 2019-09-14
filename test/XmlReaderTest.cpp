//
// Created by Leandro on 12/9/19.
//

#include "gtest/gtest.h"
#include "../servicios/XmlReader.h"
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

TEST(XmlReader, AlPedirConfiguracionesQueExistenLasDevuelveComoString) {
    XmlReader reader = XmlReader("s");

    string level = reader.getValue("/debug/level");
    string cuchillos = reader.getValue("/escenario/objetos/cuchillo/cantidad");

    EXPECT_EQ(level, "DEBUG");
    EXPECT_EQ(cuchillos, "5");
}

TEST(XmlReader, AlPedirConfiguracionesQueNoExistenDevuelveUnaCadenaVacia) {
    XmlReader reader = XmlReader("s");

    string noValido = reader.getValue("/noValido/level");
    string cuchillosNoValido = reader.getValue("/escenario/objetos/cuchillo/cantidad2");

    EXPECT_EQ(noValido, "");
    EXPECT_EQ(cuchillosNoValido, "");
}