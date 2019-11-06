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
    logger->log(DEBUG, "Se instancio un objeto de clase Saltando");
}

Saltando::~Saltando() {
    Logger *logger = Locator::logger();
    logger->log(DEBUG, "Se elimino un objeto de clase Saltando");
}

void Saltando::actualizar(Entidad *entidad) {
    if (!termine ) {
        auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
        velocidad->y = 0;
        velocidad->z = velocidadInicial + aceleracion * frames;
        if (velocidad->z == -velocidadInicial) {
            termine = true;
            velocidad->z = 0;
        }
        frames++;
    }else if( entidad->getEstado<Tipo>("tipo")->tipo() == JUGADOR  && ! entidad->getEstado<Actividad>("actividad")->activo ){
        EstadoDePersonajeServidor::reposar(entidad); //TODO
    }
}

void Saltando::caminar(Entidad *entidad, bool X_pos, bool X_neg, bool Y_pos, bool Y_neg) {
    if (Saltando::termine)
        EstadoDePersonajeServidor::caminar(entidad, X_pos, X_neg, Y_pos, Y_neg);
}

void Saltando::agachar(Entidad *entidad) {
    if (Saltando::termine)
        EstadoDePersonajeServidor::agachar(entidad);
}

void Saltando::reposar(Entidad *entidad) {
    if (Saltando::termine)
        EstadoDePersonajeServidor::reposar(entidad);
}

void Saltando::saltar(Entidad *entidad) {
    if (Saltando::termine)
        EstadoDePersonajeServidor::saltar(entidad);
}

void Saltando::golpear(Entidad *entidad) {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");

    if (!Saltando::termine) {
        if ((velocidad->z <= velocidadInicial) && (velocidad->z >= 0)) {
            if (!pateando) {
                pateando = true;
                entidad->agregarEstado("estado de personaje", new EstadoDePersonaje(PATEANDO));
                enum PERSONAJE personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
                auto* animacion = FabricaDeAnimacionesServidor::getAnimacion(personaje, "pateando");
                entidad->agregarComportamiento("animacion servidor", animacion);
            }
        }
    } else {
        EstadoDePersonajeServidor::golpear(entidad);
    }
}
