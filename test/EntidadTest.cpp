//
// Created by sebas on 21/9/19.
//

#include "gtest/gtest.h"
#include "../modelo/mapeables/Entidad.h"

TEST(Entidad, UnaEntidadDevuelveElComponenteCorrecto) {
    Entidad entidad;

    Componente i;
    entidad.agregarComponente(&i);

    auto *j = entidad.getComponente<Componente>();

    EXPECT_EQ(&i, j);
}

TEST(Entidad, SiElComponenteNoExisteDevuelveNull) {
    Entidad entidad;

    auto *j = entidad.getComponente<Componente>();

    EXPECT_EQ(j, nullptr);
}

class OtroComponente : public Componente {};

TEST(Entidad, PuedoAgregarTipoDeComponentes) {
    Entidad entidad;
    OtroComponente i;

    entidad.agregarComponente(&i);

    auto *j = entidad.getComponente<OtroComponente>();

    EXPECT_EQ(&i, j);
}

TEST(Entidad, PuedoAgregarVariosComponentesYDevelvenElCorrecto) {
    Entidad entidad;
    Componente i;
    OtroComponente j;

    entidad.agregarComponente(&i);
    entidad.agregarComponente(&j);

    auto *iDevuelto = entidad.getComponente<Componente>();
    auto *jDevuelto = entidad.getComponente<OtroComponente>();

    EXPECT_EQ(&i, iDevuelto);
    EXPECT_EQ(&j, jDevuelto);
}