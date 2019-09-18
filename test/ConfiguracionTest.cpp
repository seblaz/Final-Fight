//
// Created by sebas on 11/9/19.
//

#include "gtest/gtest.h"
#include "../servicios/ConfiguracionOld.h"

TEST(Configuraciones, PuedoObtenerConfiguracionesLuegoDeSetearlas) {
    ConfiguracionOld config(200, 100, 0, 0, 0);

    EXPECT_EQ(config.anchoDePantalla, 200);
    EXPECT_EQ(config.alturaDePantalla, 100);
}