//
// Created by sebas on 11/9/19.
//

#include "gtest/gtest.h"
#include "../servicios/Configuracion.h"

TEST(Configuraciones, PuedoObtenerConfiguracionesLuegoDeSetearlas) {
    Configuracion config(200, 100);

    EXPECT_EQ(config.anchoDePantalla, 200);
    EXPECT_EQ(config.alturaDePantalla, 100);
}