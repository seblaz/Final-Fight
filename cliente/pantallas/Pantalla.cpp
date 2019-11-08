//
// Created by sebas on 1/11/19.
//

#include "Pantalla.h"
#include "ManagerPantallas.h"
#include "../../servicios/Locator.h"

Pantalla::Pantalla(IdPantalla id, InterpreteCliente *interprete, EntradaUsuario *entradaUsuario, Vista *vista) :
        id(id),
        vista(vista),
        interprete(interprete),
        entradaUsuario(entradaUsuario) {}

IdPantalla Pantalla::getId() {
    return id;
}

void Pantalla::setManager(ManagerPantallas *manager_) {
    manager = manager_;
}

void Pantalla::interpretarNombrePantalla(stringstream &s) {
    NombrePantalla pantalla;
    pantalla.deserializar(s);
    manager->cambiarA(pantalla.getId());
}

void Pantalla::interpretarModelo(stringstream &s) {
    interprete->interpretar(s);
}

void Pantalla::graficar(SDL_Renderer *renderer) {
    vista->graficar(renderer);
}

Accion *Pantalla::getAccion(SDL_Event *e) {
    return entradaUsuario->getAccion(e);
}

void Pantalla::recibir(stringstream &s) {
    Socket *socket = Locator::socket();
    if (socket->estaDesconectado() || !socket->recibir(s)) {
        Locator::logger()->log(ERROR, "Ocurrió un error en el hilo de recepción.");
        socket->finalizarConexion();
        manager->cambiarA("error de conexion");
    };
}

void Pantalla::enviar(SDL_Event *e) {
    Accion *accion = getAccion(e);
    stringstream s;
    accion->serializar(s);
    if (Locator::socket()->estaDesconectado() || !Locator::socket()->enviar(s)) {
        Locator::logger()->log(ERROR, "Ocurrió un error en el hilo de transmisión.");
        Locator::socket()->finalizarConexion();
        manager->cambiarA("error de conexion");
    }
}

void Pantalla::iniciar() {
    Locator::mapa()->vaciarMapa();
}
