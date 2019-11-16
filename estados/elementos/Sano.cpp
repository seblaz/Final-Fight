//
// Created by sebas on 16/11/19.
//

#include "Sano.h"
#include "../../modelo/serializables/Elemento.h"
#include "RecibiendoGolpeElemento.h"
#include "Roto.h"
#include "../../servidor/notificadores/NotificadorDeGolpes.h"
#include "../../servicios/Locator.h"

void Sano::recibirGolpeDe(Entidad *jugador) {
    auto *elemento = entidad->getEstado<Elemento>("elemento");
    elemento->recibirGolpeDe();
    if(elemento->estaRoto()) {
        Locator::logger()->log(INFO, "Elemento roto.");
        jugador->getEstado<NotificadorDeGolpes>("notificador")->notificarGolpeAElemento(elemento);
        entidad->agregarComportamiento("estado", new Roto(entidad));
        Locator::mapa()->quitarElemento(entidad);
    } else {
        entidad->agregarComportamiento("estado", new RecibiendoGolpeElemento(entidad));
    }
}
