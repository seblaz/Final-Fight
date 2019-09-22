//
// Created by sebas on 21/9/19.
//

#include "gtest/gtest.h"
#include "../modelo/Entidad.h"

class UnComponente : public Estado {};

class OtroComponente : public Estado {};

TEST(Entidad, UnaEntidadDevuelveElComponenteCorrecto) {
    Entidad entidad;

    UnComponente i;
    entidad.agregarEstado("un estado", &i);

    auto *j = entidad.getEstado<UnComponente>("un estado");

    EXPECT_EQ(&i, j);
}

TEST(Entidad, SiElComponenteNoExisteDevuelveNull) {
    Entidad entidad;

    auto *j = entidad.getEstado<UnComponente>("un estado");

    EXPECT_EQ(j, nullptr);
}



TEST(Entidad, PuedoAgregarDistintosTiposDeComponentes) {
    Entidad entidad;
    OtroComponente i;

    entidad.agregarEstado( "otro estado", &i);

    auto *j = entidad.getEstado<OtroComponente>("otro estado");

    EXPECT_EQ(&i, j);
}

TEST(Entidad, PuedoAgregarVariosComponentesYDevelvenElCorrecto) {
    Entidad entidad;
    UnComponente i;
    OtroComponente j;

    entidad.agregarEstado( "un estado", &i);
    entidad.agregarEstado( "otro estado", &j);

    auto *iDevuelto = entidad.getEstado<UnComponente>( "un estado");
    auto *jDevuelto = entidad.getEstado<OtroComponente>( "otro estado");

    EXPECT_EQ(&i, iDevuelto);
    EXPECT_EQ(&j, jDevuelto);
}