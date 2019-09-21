//
// Created by sebas on 21/9/19.
//

#include "gtest/gtest.h"
#include "../modelo/mapeables/Entidad.h"

class UnComponente : public Estado {};

class OtroComponente : public Estado {};

TEST(Entidad, UnaEntidadDevuelveElComponenteCorrecto) {
    Entidad entidad;

    UnComponente i;
    entidad.agregarEstado(&i);

    auto *j = entidad.getEstado<UnComponente>();

    EXPECT_EQ(&i, j);
}

TEST(Entidad, SiElComponenteNoExisteDevuelveNull) {
    Entidad entidad;

    auto *j = entidad.getEstado<UnComponente>();

    EXPECT_EQ(j, nullptr);
}



TEST(Entidad, PuedoAgregarDistintosTiposDeComponentes) {
    Entidad entidad;
    OtroComponente i;

    entidad.agregarEstado(&i);

    auto *j = entidad.getEstado<OtroComponente>();

    EXPECT_EQ(&i, j);
}

TEST(Entidad, PuedoAgregarVariosComponentesYDevelvenElCorrecto) {
    Entidad entidad;
    UnComponente i;
    OtroComponente j;

    entidad.agregarEstado(&i);
    entidad.agregarEstado(&j);

    auto *iDevuelto = entidad.getEstado<UnComponente>();
    auto *jDevuelto = entidad.getEstado<OtroComponente>();

    EXPECT_EQ(&i, iDevuelto);
    EXPECT_EQ(&j, jDevuelto);
}