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

TEST(ManagerUsuarios, EstaPresente){
    ManagerUsuarios manager(4);
    Usuario usuario("user", "pass");

    EXPECT_EQ(false, manager.estaPresente("user"));

    manager.agregarUsuario(usuario);

    EXPECT_EQ(true, manager.estaPresente("user"));
}

TEST(ManagerUsuarios, AgregarUsuarioOk){
    ManagerUsuarios manager(4);
    Usuario usuario("user", "pass");

    manager.agregarUsuario(usuario);

    EXPECT_EQ(1, manager.getCantidadLogueados());
}

TEST(ManagerUsuarios, AgregarUsuarioYaPresente){
    ManagerUsuarios manager(4);
    Usuario usuario("user", "pass");

    manager.agregarUsuario(usuario);

    try {
        manager.agregarUsuario(usuario);

        EXPECT_EQ(true, false);
    } catch(...){
        EXPECT_EQ(true, true);
    }

}

TEST(ManagerUsuarios, AgregarUsuarioSuperaCantidadMaxima){
    ManagerUsuarios manager(1);
    Usuario usuario("user", "pass");
    Usuario usuario2("user2", "pass");

    manager.agregarUsuario(usuario);
    manager.agregarUsuario(usuario2);

    try {
        manager.agregarUsuario(usuario2);

        EXPECT_EQ(true, false);
    } catch(...){
        EXPECT_EQ(true, true);
    }

}

TEST(ManagerUsuarios, EstaLogueadoOk){
    ManagerUsuarios manager(4);
    Usuario usuario("user", "pass");

    EXPECT_EQ(false, manager.estaLogueado(usuario));

    manager.agregarUsuario(usuario);

    EXPECT_EQ(true, manager.estaLogueado(usuario));
}