//
// Created by leandro on 8/10/19.
//

#include "gtest/gtest.h"
#include "../usuario/Usuario.h"
#include "../usuario/ManagerUsuarios.h"

TEST(Usuario, UsuarioCreadoCorrecto){
    Usuario usuario("user", "pass");

    EXPECT_EQ("user", usuario.getUsuario());
    EXPECT_EQ("pass", usuario.getContrasenia());
}

TEST(ManagerUsuarios, AgregarUsuario){
    ManagerUsuarios manager(4);
    Usuario usuario("user", "pass");

    manager.agregarUsuario(usuario);

    EXPECT_EQ(1, manager.getCantidadLogueados());
}