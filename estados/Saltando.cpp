//
// Created by franco on 8/9/19.
//

#include "Saltando.h"
#include "../servicios/Locator.h"
#include "../modelo/Velocidad.h"
#include "../graficos/FabricaDeAnimacionesDeCody.h"
#include "Caminando.h"

Saltando::Saltando() {
    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se instancio un objeto de clase Saltando");
}

Saltando::~Saltando() {
    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se elimino un objeto de clase Saltando");
}

void Saltando::actualizar(Entidad *entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->y = 0;
    velocidad->z = velocidadInicial + aceleracion * frames;
    if (velocidad->z == -velocidadInicial) {
        termine = true;
        velocidad->x = 0;
        velocidad->y = 0;
        velocidad->z = 0;
    }
    frames++;
}

void Saltando::enter(Entidad *entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
    if (velocidad->x == 0) {
        auto *animacion = fabricaDeAnimaciones->saltando();
        entidad->agregarEstado("animacion", animacion);
    } else if (velocidad->x != 0) {
        auto *animacion = fabricaDeAnimaciones->saltandoAdelante();
        entidad->agregarEstado("animacion", animacion);
    }
}

void Saltando::caminar(Entidad *entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    if (Saltando::termine)
        EstadoDePersonaje::caminar(entidad, X_pos, X_neg, Y_pos, Y_neg);
}

void Saltando::agachar(Entidad *entidad) {
    if (Saltando::termine)
        EstadoDePersonaje::agachar(entidad);
}

void Saltando::reposar(Entidad *entidad) {
    if (Saltando::termine)
        EstadoDePersonaje::reposar(entidad);
}

void Saltando::saltar(Entidad *entidad) {
    if (Saltando::termine)
        EstadoDePersonaje::saltar(entidad);
}

void Saltando::golpear(Entidad *entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");

    if (!Saltando::termine) {
        if ((velocidad->z <= velocidadInicial) && (velocidad->z >= 0)) {
            if (!pateando) {
                auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesDePersonaje>("fabrica de animaciones");
                auto *animacion = fabricaDeAnimaciones->patadaBasica();
                entidad->agregarEstado("animacion", animacion);
                pateando = true;
            }
        }
    } else {
        EstadoDePersonaje::golpear(entidad);
    }
}
