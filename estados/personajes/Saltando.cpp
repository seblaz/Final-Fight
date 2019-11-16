//
// Created by franco on 8/9/19.
//

#include "Saltando.h"
#include "../../servicios/Locator.h"
#include "../../modelo/Velocidad.h"
#include "Caminando.h"
#include "../../modelo/serializables/EstadoDePersonaje.h"
#include "../../modelo/serializables/Personaje.h"
#include "../../servidor/FabricaDeAnimacionesServidor.h"
#include "../../modelo/serializables/Actividad.h"

Saltando::Saltando(Entidad *entidad) :
        EstadoDePersonajeServidor(entidad),
        armaPrevia(entidad->getEstado<Arma>("arma")->getArma()) {
    entidad->agregarEstado("arma", new Arma(ARMA::PATADA));
}

void Saltando::actualizar() {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");
    velocidad->y = 0;
    velocidad->z = velocidadInicial + aceleracion * frames;
    if (velocidad->z <= -velocidadInicial) {
        entidad->agregarEstado("arma", new Arma(armaPrevia));
        entidad->agregarComportamiento("estado", new EstadoDePersonajeServidor(entidad));
        velocidad->z = 0;
    }
    frames++;
}

void Saltando::darGolpe() {
    auto *velocidad = entidad->getEstado<Velocidad>("velocidad");

    if ((velocidad->z <= velocidadInicial) && (velocidad->z >= 0)) {
        if (!pateando) {
            pateando = true;
            entidad->agregarEstado("estado de personaje", new EstadoDePersonaje(PATEANDO));
            enum PERSONAJE personaje = entidad->getEstado<Personaje>("personaje")->getPersonaje();
            auto *animacion = FabricaDeAnimacionesServidor::getAnimacion(entidad, personaje, "pateando");
            entidad->agregarComportamiento("animacion servidor", animacion);
        }
    }
}
