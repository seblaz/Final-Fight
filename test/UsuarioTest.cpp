//
// Created by leandro on 8/10/19.
//

#include "gtest/gtest.h"
#include "../usuario/Usuario.h"

TEST(Usuario, UsuarioCreadoCorrecto){
    Usuario usuario("user", "pass");

    EXPECT_EQ("user", usuario.getUsuario());
    EXPECT_EQ("pass", usuario.getContrasenia());
}