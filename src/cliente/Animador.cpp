//
// Created by franco on 23/9/19.
//

#include "Animador.h"
#include "../modelo/serializables/EstadoDePersonaje.h"
#include "../modelo/serializables/Arma.h"
#include "../graficos/FabricaDeAnimacionesCliente.h"
#include "../servicios/Locator.h"

Animador::Animador(Entidad *entidad) : Comportamiento(entidad) {}

void Animador::actualizar() {
    string nombrePersonaje = Personaje::PersonajeACadena(entidad->getEstado<Personaje>("personaje")->getPersonaje());
    string tipoArma = Arma::armaACadena(entidad->getEstado<Arma>("arma")->getArma());
    auto *spritePersonaje = Locator::fabricaDeSprites()->getSpriteConfigPath("/sprites/personajes/" + nombrePersonaje + "/" + tipoArma + "/src");
    entidad->cambiarEstado("sprite", spritePersonaje);

    auto *estado = entidad->getEstado<EstadoDePersonaje>("estado de personaje");
    auto* fabricaDeAnimaciones = entidad->getEstado<FabricaDeAnimacionesCliente>("fabrica de animaciones");
    entidad->agregarEstado("animacion", fabricaDeAnimaciones->getAnimacion(estado->getEstado()));
}

