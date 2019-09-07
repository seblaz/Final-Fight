//
// Created by sebas on 30/8/19.
//

#include "gtest/gtest.h"
#include "../modelo/Velocidad.h"

TEST(Velocidad, VelocidadTieneMantieneElModulo) {
    Velocidad velocidad(1, 1, 1);

    EXPECT_FLOAT_EQ(velocidad.x, 1);
    EXPECT_FLOAT_EQ(velocidad.y, 1);
    EXPECT_FLOAT_EQ(velocidad.z, 1);
}