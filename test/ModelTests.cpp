//
// Created by sebas on 30/8/19.
//

#include "gtest/gtest.h"
#include<cmath>
#include "../model/Direccion.h"

TEST(SuiteDeEjemplo, TestDeEjemplo) {
    EXPECT_EQ(1, 1);
}

TEST(Direccion, DireccionTieneModulo1) {
    Direccion direccion(1, 1, 1);

    EXPECT_FLOAT_EQ(direccion.x, 1 / pow(3, 0.5));
    EXPECT_FLOAT_EQ(direccion.y, 1 / pow(3, 0.5));
    EXPECT_FLOAT_EQ(direccion.z, 1 / pow(3, 0.5));
}

TEST(Direccion, DireccionNoCambiaSiTieneModulo1) {
    Direccion direccion(1, 0, 0);

    EXPECT_EQ(direccion.x, 1);
    EXPECT_EQ(direccion.y, 0);
    EXPECT_EQ(direccion.z, 0);
}