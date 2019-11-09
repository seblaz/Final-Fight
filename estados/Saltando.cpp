//
// Created by franco on 8/9/19.
//

#include "Saltando.h"
#include "../servicios/Locator.h"
#include "../modelo/Velocidad.h"
#include "Caminando.h"
#include "../modelo/serializables/EstadoDePersonaje.h"
#include "../modelo/serializables/Personaje.h"
#include "../servidor/FabricaDeAnimacionesServidor.h"
#include "../modelo/serializables/Actividad.h"

Saltando::Saltando() {
    Logger *logger = Locator::logger();
//    logger->log(DEBUG, "Se instancio un objeto de clase Saltando");
}

Saltando::~Saltando() {
    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se elimino un objeto de clase Saltando");
}

void Saltando::actualizar(Entidad *entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->y = 0;
    velocidad->z = velocidadInicial + aceleracion * frames;
    if (velocidad->z <= -velocidadInicial) {
        auto *reposando = new EstadoDePersonajeServidor();
        entidad->agregarComportamiento("estado", reposando);
        velocidad->z = 0;
    }
    frames++;
}

void Saltando::golpear(Entidad *entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");

    if ((velocidad->z <= velocidadInicial) && (velocidad->z >= 0)) {
        if (!pateando) {
            pateando = true;
            entidad->agregarEstado("estado de personaje", new EstadoDePersonaje(PATEANDO));
            enum PERSONAJE personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
            auto *animacion = FabricaDeAnimacionesServidor::getAnimacion(personaje, "pateando");
            entidad->agregarComportamiento("animacion servidor", animacion);
        }
    }
}
