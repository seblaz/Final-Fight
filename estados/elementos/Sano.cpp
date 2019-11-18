//
// Created by sebas on 16/11/19.
//

#include "Sano.h"
#include "../../modelo/serializables/Elemento.h"
#include "../../modelo/serializables/Arma.h"
#include "RecibiendoGolpeElemento.h"
#include "Roto.h"
#include "../../servidor/notificadores/NotificadorDeGolpes.h"
#include "../../servicios/Locator.h"
#include "../../modelo/serializables/EstadoDePersonaje.h"

void Sano::recibirGolpeDe(Entidad *jugador) {
    Locator::logger()->log(INFO, "Un elemento recibió un golpe.");

    jugador->getEstado<Arma>("arma")->inicioUso();
    auto *elemento = entidad->getEstado<Elemento>("elemento");

    elemento->recibirGolpe();
    if(elemento->estaRoto()) {
        Locator::logger()->log(INFO, "Elemento roto.");
        jugador->getEstado<NotificadorDeGolpes>("notificador")->notificarGolpeAElemento(elemento);
        entidad->agregarComportamiento("estado", new Roto(entidad));
        Locator::mapa()->quitarElemento(entidad);
    } else {
        int pausas = jugador->getEstado<EstadoDePersonaje>("estado de personaje")->getEstado() == DANDO_GOLPE ? 16 : 50; // Parche para que rompa de una las cajas.
        entidad->agregarComportamiento("estado", new RecibiendoGolpeElemento(entidad, pausas));
    }
}
