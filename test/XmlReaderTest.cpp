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
    XmlReader reader = XmlReader();

    string level = reader.getValue("/debug/level");
    string cuchillos = reader.getValue("/escenario/objetos/cuchillo/cantidad");

    EXPECT_EQ(level, "DEBUG");
    EXPECT_EQ(cuchillos, "5");
}