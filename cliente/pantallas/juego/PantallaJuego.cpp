//
// Created by sebas on 2/11/19.
//

#include <algorithm>
#include <utility>
#include "PantallaJuego.h"
#include "../../ActualizadorCliente.h"
#include "../../../servicios/Locator.h"
#include "../ManagerPantallas.h"

PantallaJuego::PantallaJuego(IdPantalla id, Mapa *mapa) :
        Pantalla(std::move(id)), mapa(mapa), actualizador(mapa), receptor(Locator::socket()),
        trasmision(Locator::socket(), &entrada) {}


void PantallaJuego::iniciar() {
    hiloRecepcion = receptor.recibirEnHilo();
    hiloTransmision = trasmision.transmitirEnHilo();
}

void PantallaJuego::actualizar(SDL_Event *evento) {
    stringstream s;
    if (!receptor.conexionEstaActiva()) {
        manager->cambiarA("error de conexion");
    } else {
        receptor.devolverStreamMasReciente(s);
        actualizador.actualizarEntidades(s, &trasmision);
        actualizarEntidades();
    }
}

void PantallaJuego::actualizarEntidades() {
    auto entidades = mapa->devolverEntidades();

    sort(entidades.begin(), entidades.end(), [](Entidad *a, Entidad *b) {
        return a->getEstado<Posicion>("posicion")->getY() > b->getEstado<Posicion>("posicion")->getY();
    });

    for (auto entidad : entidades) {
        auto comportamientos = entidad->getComportamientos();
        for (auto *comportamiento : comportamientos) {
            comportamiento->actualizar(entidad);
        }
    }
}

void PantallaJuego::finalizar() {
    trasmision.finalizar();
    receptor.finalizar();
    pthread_join(hiloTransmision, nullptr);
    pthread_join(hiloRecepcion, nullptr);
}